#include "scadlexer.h"
#include <Qsci/qsciscintilla.h>

ScadLexer::ScadLexer(QObject *parent) :
    QsciLexerCustom(parent)
{
    keywordsList << "if" << "else"  << "cirlce" << "sphere" <<
                    "function"  << "module"  << "use" << "cylinder"  <<
                    "include";
}

ScadLexer::~ScadLexer()
{;
}


void ScadLexer::styleText(int start, int end)
{
    if(!editor())
        return;


    char * data = new char[end - start + 1];

    editor()->SendScintilla(QsciScintilla::SCI_GETTEXTRANGE, start, end, data);
    QString source(data);
    delete [] data;
    if(source.isEmpty())
        return;


    highlightKeywords(source, start);
}

void ScadLexer::highlightKeywords(const QString &source, int start)
{
    foreach(QString word, keywordsList) { 
        if(source.contains(word)) {
            int p = source.count(word); 
            int index = 0; 
            while(p != 0) {
                int begin = source.indexOf(word, index); 
                index = begin+1; 

                startStyling(start + begin); 
                setStyling(word.length(), Keyword); 
                startStyling(start + begin); 

                p--;
            }
        }
    }
}

QColor ScadLexer::defaultColor(int style) const
{
    switch(style) {
        case Keyword:
            return Qt::blue;
    }
    return Qt::black;
}

QString ScadLexer::description(int style) const
{
    switch(style) {
        case Default:
            return "Default";
        case Keyword:
            return "Keyword";
    }
    return QString(style);
}

const char * ScadLexer::language() const
{
    return "SCAD";
}
