#ifndef USERMODELS_H
#define USERMODELS_H

#include <map>
#include <memory>
#include <string>

class User {
public:
  virtual std::string getName() = 0;
  virtual void setName(const std::string &name) = 0;
};

using UserPtr = std::shared_ptr<User>;

class TestTaker : public User {
public:
  std::string getName() override { return name; }
  void setName(const std::string &name_) override { name = name_; }

private:
  std::string name;
};

class TestWriter : public User {
public:
  std::string getName() override { return name; };
  void setName(const std::string &name_) override { name = name_; };

  virtual std::string getPassword() { return password; };
  virtual void setPassword(const std::string &password_) { password = password_; }

private:
  std::string name;
  std::string password;
};

class UserAbstractFactory {
public:
  virtual UserPtr get(const std::string &key) = 0;
};

using UserAbstractFactoryPtr = std::shared_ptr<UserAbstractFactory>;

class UserFactory : public UserAbstractFactory {
public:
  static bool addFactory(const std::string &key, const UserAbstractFactoryPtr &factory) {
    m.insert({key, factory});
    return true;
  }

  UserPtr get(const std::string &key) override { return m.at(key)->get(key); }

private:
  static std::map<std::string, UserAbstractFactoryPtr> m;
};

std::map<std::string, UserAbstractFactoryPtr> UserFactory::m;

class TestTakerFactory : public UserAbstractFactory {
public:
  UserPtr get(const std::string &key) override {
    TestTaker taker;
    taker.setName(key);
    return std::make_shared<TestTaker>(taker);
  }
};

class TestWriterFactory : public UserAbstractFactory {
public:
  UserPtr get(const std::string &key) override {
    TestWriter writer;
    writer.setName(key);
    return std::make_shared<TestWriter>(writer);
  }
};

#endif // USERMODELS_H
