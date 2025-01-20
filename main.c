#include "gtk/gtk.h"
#include "string.h"
#include "stdio.h"
#include "Checks.h"
#include "stdbool.h"
#include "ctype.h"
#include "CalculationCall.h"



GtkWidget *label;
GtkWidget *grid;
char RenderedlabelContent[255];
bool TheresAlreadySpecialOperator = false;
bool TheresAlreadyOperator = false;
bool UnclosedParenthese = false;
int NumberOfUnclosedParentheses = 0;
int NumberOfSpecialOp = 0;
char Tokens[255][255];
int NumberOfTokens = 0;
bool IsLastOperator = false;
bool IsLastNumber = false;

static void Tokenize()
{
  //char AlterStr[255] = {"l005.55+55.22"};
  //char Tokens[255][255];
  char tempchar[2];
  int tempcounter = 0;
  int numberOfAlterStr = 0;
  char tempstr[5];
  for (int i = 0; i < strlen(RenderedlabelContent); i++)
  {
    //printf("%c",AlterStr[i]);
    tempcounter = 0;
    if (isdigit(RenderedlabelContent[i]) || RenderedlabelContent[i] == '.')
    {
      while (isdigit(RenderedlabelContent[i]) || RenderedlabelContent[i] == '.')
      {
        while(tempcounter == 0 && (RenderedlabelContent[i] == '0' || RenderedlabelContent[i] == '.'))
        {
          i++;
        }
        tempcounter++;
        tempstr[0] = RenderedlabelContent[i];
        tempstr[1] = '\0';
        strcat(Tokens[numberOfAlterStr],tempstr);
        i++;
      }
      numberOfAlterStr++;
      //i++;
    }
    tempchar[0] = RenderedlabelContent[i];
    tempchar[1] = '\0';
    if (IsFloatOperator(RenderedlabelContent[i]))
    {
      strcat(Tokens[numberOfAlterStr],"1");
      numberOfAlterStr++;
      tempstr[0] = RenderedlabelContent[i];
      tempstr[1] = '\0';
      strcat(Tokens[numberOfAlterStr],tempstr);
      numberOfAlterStr++;
      while (isalpha(RenderedlabelContent[i]))
      {
        i++;
      }
      //i++;
    }
    else if (isOperator(tempchar))
    {
      tempstr[0] = RenderedlabelContent[i];
      tempstr[1] = '\0';
      strcat(Tokens[numberOfAlterStr],tempstr);
      numberOfAlterStr++;
    }
    else if (RenderedlabelContent[i] == '(')
    {
      tempstr[0] = RenderedlabelContent[i];
      tempstr[1] = '\0';
      strcat(Tokens[numberOfAlterStr],tempstr);
      numberOfAlterStr++;
      //i++;    
    }    
    else if (RenderedlabelContent[i] == ')')
    {
      tempstr[0] = RenderedlabelContent[i];
      tempstr[1] = '\0';
      strcat(Tokens[numberOfAlterStr],tempstr);
      numberOfAlterStr++;
      //i++;    
    }
  }
  for (int i = 0; i < numberOfAlterStr; i++)
  {
    printf("[%s]",Tokens[i]);
  }
}

static void ChangeLabelText (const char *str)
{
  //do the calculation 
  if (str[0] == '=' && (!TheresAlreadyOperator && IsLastNumber))
  {
    if (NumberOfSpecialOp > 0)
    {
      for (int i = 0; i < NumberOfSpecialOp; i++)
      {
        strcat(RenderedlabelContent,")");
        //strcat(Tokens[NumberOfTokens],")");
        //NumberOfTokens++;
      }
      NumberOfSpecialOp = 0;
    }    
    if (NumberOfUnclosedParentheses > 0)
    {
      for (int i = 0; i < NumberOfUnclosedParentheses; i++)
      {
        strcat(RenderedlabelContent,")");
        //strcat(Tokens[NumberOfTokens],")");
        //NumberOfTokens++;
      }
      NumberOfUnclosedParentheses = 0;
    }
    for (int i = 0; i < NumberOfTokens; i++)
    {
      printf("%s",Tokens[i]);
    }    
    Tokenize();
    strcpy(RenderedlabelContent,CalculationCall(Tokens));
    gtk_label_set_text(GTK_LABEL(label),RenderedlabelContent);
    int numElements = 0;

    // Loop through the array to count initialized elements
    for (int i = 0; i < 255; i++) {
      if (strlen(Tokens[i]) == 0) {
        break; // Stop counting when an empty string is found
      }
      numElements++;
    }
    for (int i = 0; i < numElements; i++)
    {
      strcpy(Tokens[i],"\0");
    }
    
    printf("%s",RenderedlabelContent);

  }
  /////////////////////////////////////////////////////////////////////////////
  if (strcmp(str,"DEL")==0)
  {
    strcpy(RenderedlabelContent,"\0");
    gtk_label_set_text(GTK_LABEL(label),RenderedlabelContent);
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  //Special Operator
  if (IsFloatOperator(str[0]) && (RenderedlabelContent[0] == '\0' ||(TheresAlreadyOperator || TheresAlreadySpecialOperator) && IsLastOperator) && str[0] != '=')
  {
    //printf("WORKD S");
    if (strcmp(str,"sin") == 0)
    {
      TheresAlreadySpecialOperator = true;
      IsLastOperator = true;
      IsLastNumber = false;
      UnclosedParenthese = true;
      NumberOfSpecialOp++;
      strcat(RenderedlabelContent, "i");
      strcat(RenderedlabelContent, "(");
      gtk_label_set_text(GTK_LABEL(label),RenderedlabelContent);
    }
    else if (strcmp(str,"exp") == 0)
    {
      TheresAlreadySpecialOperator = true;
      IsLastOperator = true;
      IsLastNumber = false;
      UnclosedParenthese = true;
      NumberOfSpecialOp++;
      strcat(RenderedlabelContent, "x");
      strcat(RenderedlabelContent, "(");
      gtk_label_set_text(GTK_LABEL(label),RenderedlabelContent);
    }
    else 
    {
      TheresAlreadySpecialOperator = true;
      IsLastOperator = true;
      IsLastNumber = false;
      UnclosedParenthese = true;
      NumberOfSpecialOp++;
      strcat(RenderedlabelContent, str);
      strcat(RenderedlabelContent, "(");
      gtk_label_set_text(GTK_LABEL(label),RenderedlabelContent);
    }

  }
  //////////////////////////////////////////////////////////////////////////////////
  //Normal Operator
  else if (RenderedlabelContent[0] != '\0' && isOperator((char *)str) && !TheresAlreadyOperator && !TheresAlreadyOperator && !IsFloatOperator(str[0]))
  {
    IsLastOperator = true;
    TheresAlreadyOperator = true;
    IsLastNumber = false;
    strcat(RenderedlabelContent,str);
    gtk_label_set_text(GTK_LABEL(label),RenderedlabelContent);
  }
  //////////////////////////////////////////////////////////////////////////////////////////////////
  //Number check
  if(isdigit(str[0]) || str[0] == '.' || (strcmp(str,"pi") == 0))
  {
    if ((strcmp(str,"pi") == 0))
    {
      TheresAlreadyOperator = false;
      IsLastOperator = false;
      IsLastNumber = true;
      strcat(RenderedlabelContent,"3.14");
      gtk_label_set_text(GTK_LABEL(label),RenderedlabelContent);
    }
    //printf("WORKD N");
    else if (TheresAlreadySpecialOperator || TheresAlreadyOperator)
    {
      TheresAlreadyOperator = false;
      IsLastOperator = false;
      IsLastNumber = true;
      strcat(RenderedlabelContent,str);
      gtk_label_set_text(GTK_LABEL(label),RenderedlabelContent);
    }
    else
    {
      TheresAlreadyOperator = false;
      IsLastOperator = false;
      IsLastNumber = true;
      strcat(RenderedlabelContent,str);
      gtk_label_set_text(GTK_LABEL(label),RenderedlabelContent);
    }
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////
  //check )
  if (str[0] == '(' && (TheresAlreadyOperator || UnclosedParenthese || RenderedlabelContent[0] == '\0'))
  {
    //printf("WORKD (");
    NumberOfUnclosedParentheses++;
    UnclosedParenthese = true;
    IsLastNumber = false;
    strcat(RenderedlabelContent,"(");
    gtk_label_set_text(GTK_LABEL(label),RenderedlabelContent);
    //strcat(Tokens[NumberOfTokens],"(");
    //NumberOfTokens++;
  }
  //////////////////////////////////////////////////////////////////////////////////////////
  //check (
  if ( str[0] == ')' && ( UnclosedParenthese || NumberOfUnclosedParentheses > 0) && (!IsLastOperator || IsLastNumber))
  {
    //printf("WORKD )");
    NumberOfUnclosedParentheses--;
    if (NumberOfUnclosedParentheses > 0)
    {
      UnclosedParenthese = false;
    }
    strcat(RenderedlabelContent,")");
    gtk_label_set_text(GTK_LABEL(label),RenderedlabelContent);
    //strcat(Tokens[NumberOfTokens],")");
    //NumberOfTokens++;
  }
}

static void ButtonClick(GtkWidget *widget,gpointer data)
{
  const char *labelString = gtk_button_get_label(GTK_BUTTON(widget));
  ChangeLabelText(labelString);
}

static void activate (GtkApplication *app,gpointer user_data)
{ 
  //define app components
  //here we make the apps widgets
  GtkWidget *window;
  //variable that contains the calculators preview
  GtkWidget *TextPrintWidget = gtk_text_view_new();
  //button 
  GtkWidget *MyButtons;

  /* create a new window, and set its title */
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Advanced Calculater");
  gtk_window_set_default_size(GTK_WINDOW(window),500,600);
  //here we set the box
  //GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  //gtk_widget_set_vexpand(vbox,true);
  //gtk_widget_set_hexpand(vbox,true);
  /* Here we construct the container that is going pack our buttons */
  grid = gtk_grid_new ();
  gtk_widget_set_vexpand(grid,TRUE);
  gtk_widget_set_hexpand(grid,TRUE);
  //gtk_box_pack_start(GTK_BOX(window),grid,true,true);




  //init the label and add it to the grid
  label = gtk_label_new("0");
  gtk_grid_attach(GTK_GRID(grid),label,0,0,7,2);

  const char *calculatorLabels[6][8] = 
  {
    {"","","","(",")","%","DEL"},
    {"","sin","ln","7","8","9","/"},
    {"pi","cos","log","4","5","6","*"},
    {"e","tan","sqrt","1","2","3","-"},
    {"!","exp","power","0",".","=","+"}
  };

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      MyButtons = gtk_button_new_with_label(calculatorLabels[i][j]);
      g_signal_connect(MyButtons,"clicked",G_CALLBACK(ButtonClick),NULL);
      gtk_grid_attach(GTK_GRID(grid),MyButtons,j,i+3,1,1);
      //printf(" %s |",calculatorLabels[i][j]);
    }    
  }
  
  /* Pack the container in the window */
  gtk_window_set_child (GTK_WINDOW (window), grid);
  //create the window
  gtk_window_present (GTK_WINDOW (window));
}

int main (int argc,char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
