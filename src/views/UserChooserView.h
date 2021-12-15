#ifndef USERCHOOSERVIEW_H
#define USERCHOOSERVIEW_H

#include "ui/ui_user_chooser.h"
#include <QMainWindow>

class UserChooserView : public QMainWindow {
  Q_OBJECT

public:
  explicit UserChooserView(QWidget *parent = nullptr) { ui->setupUi(this); }

  std::string chooseUser();

private:
  QSharedPointer<Ui::MainWindow> ui = QSharedPointer<Ui::MainWindow>(new Ui::MainWindow);
};

#endif // USERCHOOSERVIEW_H
