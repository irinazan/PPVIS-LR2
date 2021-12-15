#include "controllers/UserControllers.h"
#include "models/UserModels.h"
#include "views/UserChooserView.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  UserFactory userFactory;
  TestTakerFactory testTakerFactory;
  TestWriterFactory TestWriterFactory;

  UserControllerFactory userControllerFactory;
  TestTakerControllerFactory testTakerControllerFactory;
  TestWriterControllerFactory TestWriterControllerFactory;

  UserChooser userChooser;
  UserControllerPtr userController;
  userChooser.chooseUser("");
  QApplication::exec();
}
