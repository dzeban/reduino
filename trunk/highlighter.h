#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QDebug>

class QCppHighlighter : public QSyntaxHighlighter
{
        Q_OBJECT
public:
  QCppHighlighter(QTextDocument *parent = 0);
protected:
  void highlightBlock(const QString &text);
private:
  struct HighlightingRule
  {
    QRegExp pattern;
    QTextCharFormat format;
  };
  QVector<HighlightingRule> highlightingRules;
  QRegExp commentStartExpression;
  QRegExp commentEndExpression;
  QTextCharFormat keywordFormat;
  QTextCharFormat functionFormat;
  QTextCharFormat defFormat;
  QTextCharFormat includeClassFormat;
  QTextCharFormat singleLineCommentFormat;
  QTextCharFormat multiLineCommentFormat;
  QTextCharFormat quotationFormat;
  QTextCharFormat numberFormat;
};

#endif // HIGHLIGHTER_H
