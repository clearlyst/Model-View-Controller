#include <iostream>
#include <string>

class model_t {
private:
    std::string data;
public:
    void set(const std::string& data) {
        this->data = data;
    }

    std::string get() const {
        return this->data;
    }
};

class view_t {
public:
    void display(const std::string& data) {
        std::cout << "data: " << data << std::endl;
    }
};

class controller_t {
private:
    model_t& model;
    view_t& preview;
public:
    controller_t(model_t& m, view_t& v) : model(m), preview(v) { }

    void setup_model_data(const std::string& data) {
        model.set(data);
    }

    void view() {
        preview.display(model.get());
    }
};

int main() {
    model_t model;
    view_t view;
    controller_t controller(model, view);

    controller.setup_model_data("Hello World!");
    controller.view();

    controller.setup_model_data("All in pain.");
    controller.view();

    system("pause");
}