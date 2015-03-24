#ifndef QSCILEXERASM_H
#define QSCILEXERASM_H
#include<Qsci/qscilexercustom.h>

class ScadLexer : public QsciLexerCustom
{
    Q_OBJECT
public:
    explicit ScadLexer(QObject *parent = 0);
    ~ScadLexer();

    void styleText(int start, int end);

    void highlightKeywords(const QString &source, int start);

    const char * language() const;

    QColor defaultColor(int style) const;

    QString description(int style) const;


    enum {
        Default = 0,
        Comment = 1,
        Keyword = 2
    };
private:
    ScadLexer(const ScadLexer &);
    ScadLexer &operator=(const ScadLexer &);
    QStringList keywordsList;
    
};

#endif 
