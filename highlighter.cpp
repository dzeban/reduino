#include "highlighter.h"


QCppHighlighter::QCppHighlighter(QTextDocument *parent)
        : QSyntaxHighlighter(parent)
{
  HighlightingRule rule;
  keywordFormat.setForeground(Qt::darkBlue);
  keywordFormat.setFontWeight(QFont::Bold);
  keywordFormat.setFontFamily("Verdana");
  functionFormat.setForeground(QColor(200,165,50));
  functionFormat.setFontWeight(QFont::Normal);

  QStringList keywordPatterns;
//  if|else|for|switch|case|while|do|break|continue|return|boolean|char|byte|int|unsigned int|long|unsigned long|float|double|string|array|void
  keywordPatterns << "\\bif\\b" << "\\belse\\b" << "\\bfor\\b" << "\\bchar\\b" << "\\btrue\\b" << "\\bfalse\\b"
                  << "\\bswitch\\b" << "\\bcase\\b" << "\\bwhile\\b"
                  << "\\bdo\\b" << "\\bbreak\\b" << "\\continue\\b"
                  << "\\breturn\\b" << "\\bboolean\\b" << "\\char\\b"
                  << "\\bbyte\\b" << "\\bint\\b" << "\\bunsigned int\\b"
                  << "\\blong\\b" << "\\bunsigned long\\b" << "\\bfloat\\b"
                  << "\\bdouble\\b" << "\\bstring\\b" << "\\barray\\b"
                  << "\\bvoid\\b" ;

  QStringList functionPatterns;
//  if|else|for|switch|case|while|do|break|continue|return|boolean|char|byte|int|unsigned int|long|unsigned long|float|double|string|array|void
  functionPatterns << "\\bdigitalRead\\b" << "\\bdigitalWrite\\b" << "\\bdigitalWrite\\b" <<
                    //  "\\bSerial\\b" <<
                      "\\banalogWrite\\b" << "\\bplayTone\\b" <<
                      "\\bplayPattern\\b" <<"\\bdelay\\b" << "\\btone\\b" << "\\bnoTone\\b" <<
                      "\\bdelayMicroseconds\\b" << "\\bpinMode\\b" << "\\battachInterrupt\\b" ;

  foreach (QString pattern, functionPatterns) {
    rule.pattern = QRegExp(pattern);
    rule.format = functionFormat;
    highlightingRules.append(rule);
  }

  foreach (QString pattern, keywordPatterns) {
    rule.pattern = QRegExp(pattern);
    rule.format = keywordFormat;
    highlightingRules.append(rule);
  }

  numberFormat.setForeground(Qt::blue);
  rule.pattern = QRegExp("\\b[+|-]?[0-9]+");
  rule.format = numberFormat;
  highlightingRules.append(rule);

  defFormat.setForeground(Qt::darkRed);
  QStringList defPatterns;
  defPatterns << "\\#\\s*include" << "\\#\\s*define" << "\\#\\s*ifdef"
              << "\\#\\s*ifndef" << "\\#\\s*else"<< "\\#\\s*endif";
  foreach (QString pattern, defPatterns) {
    rule.pattern = QRegExp(pattern);
    rule.format = defFormat;
    highlightingRules.append(rule);
  }

  includeClassFormat.setForeground(Qt::blue);
  rule.pattern = QRegExp("\\<[A-Za-z]+\\>");
  rule.format = includeClassFormat;
  highlightingRules.append(rule);

  singleLineCommentFormat.setForeground(Qt::darkGreen);
  rule.pattern = QRegExp("//[^\n]*");
  rule.format = singleLineCommentFormat;
  highlightingRules.append(rule);

  multiLineCommentFormat.setForeground(Qt::darkGreen);

  quotationFormat.setForeground(Qt::darkRed);
  rule.pattern = QRegExp("\".*\"");
  rule.format = quotationFormat;
  highlightingRules.append(rule);

  rule.pattern = QRegExp("\'.*\'");
  rule.format = quotationFormat;
  highlightingRules.append(rule);

  commentStartExpression = QRegExp("/\\*");
  commentEndExpression = QRegExp("\\*/");
}

/*^**************************************************************************^*/
/*- QCppHighlighter :: Overridden Method.                                    -*/
/*^**************************************************************************^*/

void QCppHighlighter::highlightBlock(const QString &text)
{
  foreach (HighlightingRule rule, highlightingRules) {
    QRegExp expression(rule.pattern);
    int index = text.indexOf(expression);
    while (index >= 0) {
      int length = expression.matchedLength();
      setFormat(index, length, rule.format);
      index = text.indexOf(expression, index + length);
    }
  }
  setCurrentBlockState(0);
  int startIndex = 0;
  if (previousBlockState() != 1) {
    startIndex = text.indexOf(commentStartExpression);
  }
  while (startIndex >= 0) {
    int endIndex = text.indexOf(commentEndExpression, startIndex);
    int commentLength;
    if (endIndex == -1) {
      setCurrentBlockState(1);
      commentLength = text.length() - startIndex;
    } else {
      commentLength = endIndex - startIndex +
                      commentEndExpression.matchedLength();
    }
    setFormat(startIndex, commentLength, multiLineCommentFormat);
    startIndex = text.indexOf(commentStartExpression,
                              startIndex + commentLength);
  }
}
