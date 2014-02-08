#ifndef DESKTOPSEARCH_H
#define DESKTOPSEARCH_H

#include <QtGui/QMainWindow>
#include "ui_desktopsearch.h"
#include <QEvent>
#include <QProcess>
#include "Types.h"
#include <QModelIndex>

struct HISTORY_ITEM 
{
	QString	term;
	int		rank;
};

class DesktopSearch : public QMainWindow
{
	Q_OBJECT

public:
	DesktopSearch(QWidget *parent = 0, Qt::WFlags flags = 0);
	~DesktopSearch();

public slots:
	void OnSearchBtnClicked();
	void ShowResult(QList<DSFileItem> *);
	void readResult( QList<DSFileItem> * );
	void OnEdit(QString);
	void OnItemDoubleClicked(int,int);
	void OnHistoryItemDoubleClicked(QModelIndex);

signals:
	void Signal_SearchResult(QString);

private:
	Ui::DesktopSearchClass ui;
	QProcess	*	es;
	QPoint			dragPosition;
	QString			esPath;
	void SearchIt(QString);
	void SwitchWholeTextSearchMode();
	bool			isFullTextModeOn;
	QList<HISTORY_ITEM*>	historyList;

protected:
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void keyPressEvent(QKeyEvent *event);
};

#endif // DESKTOPSEARCH_H
