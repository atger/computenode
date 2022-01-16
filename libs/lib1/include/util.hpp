#include <QTextStream>
constexpr int STR_EQUAL = 0;

void useTextStream() {
	QTextStream out(stdout);
	QString a {"started"};
	a.append(" to");
	a.prepend("I ");
	out << a << Qt::endl;
	out << "The a string has " << a.count() << " characters" << Qt::endl;
	out << a.toUpper() << Qt::endl;
	out << a.toLower() << Qt::endl;
	out << a.at(5).isNull() << Qt::endl;
	QString s1 = "There are %1 roses";
	int n = 24;
	out << s1.length() << Qt::endl;
	out << s1.arg(n) << Qt::endl;
	out << s1.right(4) << Qt::endl;
	out << s1.left(4) << Qt::endl;
	out << s1.mid(4) << Qt::endl;
	QStringRef sub(&s1,3,7);
	out << sub.toString() << Qt::endl;

	for(QChar qc: s1) {
		out << qc << " ";
	}
	out << Qt::endl;

	// equality
	
	a = "Rain" ;
	QString b { "rain" };
	QString c { "rain\n" };

	if (QString::compare(a,b) == STR_EQUAL) {
		out << "a and b are equal" << Qt::endl;
	} else {
		out << "a and b are not equal" << Qt::endl;
	}

	out << "In case insensitive comparison: " << Qt::endl;

	if (QString::compare(a,b, Qt::CaseInsensitive) == STR_EQUAL) {
		out << "a and b are equal" << Qt::endl;
	} else {
		out << "a and b are not equal" << Qt::endl;
	}

	c.chop(1);
	out << c << Qt::endl;
	
	out << "Converting String: " << Qt::endl;
	QString x { "25" };
	QString y { "35" };
	QString z;
	out << "x to int: " << x.toInt() << Qt::endl;
	out << "y to int: " << y.toInt() << Qt::endl;
	out << "set z to: " << z.setNum(7) << Qt::endl;

	out << "Letters: " << Qt::endl;
	int digits = 0;
	int letters = 0;
	int spaces = 0;
	int puncts = 0;
	QString ls { "This is a very long 12 words string, but i like it." };
	for (QChar s: ls) {
		if (s.isDigit()) {
			digits++;
		} else if (s.isLetter()) {
			letters++;
		} else if (s.isSpace()) {
			spaces++;
		} else if (s.isPunct()) {
			puncts++;
		}
	}
	out << QString("There are %1 characters.").arg(ls.length()) << Qt::endl;
	out << QString("There are %1 digits.").arg(digits) << Qt::endl;
	out << QString("There are %1 letters.").arg(letters) << Qt::endl;
	out << QString("There are %1 spaces.").arg(spaces) << Qt::endl;
	out << QString("There are %1 punctuation characters.").arg(puncts) << Qt::endl;
}
