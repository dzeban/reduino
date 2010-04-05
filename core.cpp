#include <QFile>

QString get_file_content(QString filename)
{
    QString file_content;

    QFile file(filename);
    if (file.open(QFile::ReadOnly))
	file_content = file.readAll();

    if(file_content=="")
	int i=2;

    file.close();
    return file_content;
}
