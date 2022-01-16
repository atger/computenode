#include <QVector>
#include <QTextStream>

void useVector() {
	QTextStream out(stdout);
	QVector<int> vals = {1,2,3,4,5,6,7,8,9};
	out << QString("Vector size: %1").arg(vals.size()) << Qt::endl;
	out << QString("First element: %1").arg(vals.first()) << Qt::endl;
	out << "Last Element: " << vals.last() << Qt::endl;
	vals.append(10);
	vals.prepend(0);
	for (int val : vals) {
		out << val << " ";
	}
	out << Qt::endl;
}
