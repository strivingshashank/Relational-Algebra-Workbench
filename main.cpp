#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <vector>
#include <string>
#include <sstream>

template <typename DATA_TYPE>
using vector = std::vector<DATA_TYPE>;

template <typename DATA_TYPE>
using matrix = std::vector<std::vector<DATA_TYPE>>;

using string = std::string;

/* Wrapper for ftxui::vbox() */
inline ftxui::Element VBox(ftxui::Elements elements) {
  return ftxui::vbox(elements);
}

/* Wrapper for ftxui::hbox() */
inline ftxui::Element HBox(ftxui::Elements elements) {
  return ftxui::hbox(elements);
}

/* Wrapper for ftxui::text() */
inline ftxui::Element Text(const string& displayString) {
  return ftxui::text(displayString);
}

inline ftxui::Element Border(ftxui::Element element) {
  return ftxui::border(element);
}

ftxui::Element drawTable(const matrix<string>& dataTable) {
  ftxui::Elements elementRows;
  
  for (const auto& dataRow : dataTable) {
    ftxui::Elements elementColumns;

    for (const auto& dataCell : dataRow) {
      elementColumns.push_back(Border(Text(dataCell)));
    }

    elementRows.push_back(HBox(std::move(elementColumns)));
  }

  return VBox(std::move(elementRows)); 
}

// ftxui::ftxui::Element drawFunction() {
//   std::vector<ftxui::ftxui::Element> windowContentVector;
//   ftxui::ftxui::Element windowTitle = ftxui::text("What say?") | ftxui::bold;

//   windowContentVector.emplace_back(ftxui::text("Shashank da Superb") | ftxui::bold | ftxui::color(ftxui::Color::Green));
//   windowContentVector.emplace_back(ftxui::separator());
//   windowContentVector.emplace_back(ftxui::text("String1") | ftxui::border | ftxui::color(ftxui::Color::Yellow));
//   windowContentVector.emplace_back(ftxui::text("String2") | ftxui::border | ftxui::color(ftxui::Color::SkyBlue1));
//   windowContentVector.emplace_back(ftxui::text("String3") | ftxui::border | ftxui::color(ftxui::Color::Red));

//   ftxui::ftxui::Element windowContent = ftxui::hbox({ftxui::vbox(windowContentVector)});
//   // ftxui::ftxui::Element windowContent = ftxui::hbox(windowContentVector);

//   ftxui::ftxui::Element window = ftxui::window(windowTitle, windowContent) | ftxui::border;
  
//   return window;
// }

int main() {
  matrix<string> dataTable = {
    {"Name","Age","City"},
    {"Shashank","21","Kaulagarh"},
    {"Shailesh","50", "Dehradun"}
  };
  
  ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();
  ftxui::Component renderer = ftxui::Renderer([&dataTable]{
    return drawTable(dataTable);
  });

  screen.Loop(renderer);
  
  return 0;
}