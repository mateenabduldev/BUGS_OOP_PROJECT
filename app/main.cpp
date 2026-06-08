#include "Application/Application.h"
#include <filesystem>
int main() {
    std::filesystem::current_path(PROJECT_ROOT);
    Application app;
    app.run();
    return 0;
}