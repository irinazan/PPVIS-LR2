#ifndef USERCONTROLLERS_H
#define USERCONTROLLERS_H

#include "models/UserModels.h"
#include "views/UserChooserView.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

class UserController {
public:
  virtual void startUserWork() = 0;
};

using UserControllerPtr = std::shared_ptr<UserController>;

class TestTakerController : public UserController {
public:
  void startUserWork() override {}

private:
  UserPtr user;
};

class TestWriterController : public UserController {
public:
  void startUserWork() override {}

private:
  UserPtr user;
};

class UserControllerAbstractFactory {
public:
  virtual UserControllerPtr get(const UserPtr &key) = 0;
};

using UserControllerAbstractFactoryPtr = std::shared_ptr<UserControllerAbstractFactory>;

class UserControllerFactory : public UserControllerAbstractFactory {
public:
  static bool addFactory(const UserPtr &key, const UserControllerAbstractFactoryPtr &factory) {
    m.insert({key, factory});
    return true;
  }

  UserControllerPtr get(const UserPtr &key) override { return m.at(key)->get(key); }

private:
  static std::map<UserPtr, UserControllerAbstractFactoryPtr> m;
};

std::map<UserPtr, UserControllerAbstractFactoryPtr> UserControllerFactory::m;

class TestTakerControllerFactory : public UserControllerAbstractFactory {
public:
  UserControllerPtr get(const UserPtr &key) override {}
};

class TestWriterControllerFactory : public UserControllerAbstractFactory {
public:
  UserControllerPtr get(const UserPtr &key) override {}
};

class UserManager {
public:
  bool checkUser(const UserPtr &user) {
    for (const auto &u : usersList) {
      if (user->getName() == u->getName()) {
        return true;
      }
    }
    return false;
  }

private:
  std::vector<UserPtr> usersList;
};

class UserChooser {
public:
  UserPtr chooseUser(const std::string &name) {
    UserChooserView *view = new UserChooserView;
    view->show();
    return nullptr;
  }
};

#endif // USERCONTROLLERS_H
