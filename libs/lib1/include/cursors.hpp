#include <QWidget>
#include <QLabel>

class Cursors: public QWidget {
	
	Q_OBJECT
	
	public:
		Cursors(QWidget *parent = nullptr);
	
	private slots:
		void onPlus();
	    void onMinus();
	
	private:
		QLabel *label;
};
