#include "mainwindow.h"
#include "scadlexer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qsci = new QsciScintilla; 
    setCentralWidget(qsci); 
    ScadLexer * lexer = new ScadLexer(this); 
    qsci->setLexer(lexer); 
    lexer->setFont( QFont("Courier New") ); 
    
    qsci->setCaretLineVisible(true);
    qsci->setCaretLineBackgroundColor(QColor("gainsboro"));

    qsci->setAutoIndent(true);
    qsci->setIndentationWidth(4);

    qsci->setMarginsBackgroundColor(QColor("gainsboro"));
    qsci->setMarginLineNumbers(1, true);
    qsci->setMarginWidth(1, 50);

    qsci->setBraceMatching(QsciScintilla::SloppyBraceMatch);
    qsci->setMatchedBraceBackgroundColor(Qt::yellow);
    qsci->setUnmatchedBraceForegroundColor(Qt::blue);
}

MainWindow::~MainWindow()
{
    
}
