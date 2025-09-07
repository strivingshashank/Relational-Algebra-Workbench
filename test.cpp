#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <vector>
#include <string>
#include <sstream>

template <typename DATA_TYPE>
using Vector = std::Vector<DATA_TYPE>;

using String = std::string;
using Element = ftxui::Element;
using Elements = Vector<Element>;

/* Wrapper for ftxui::vbox() */
inline Element VBox(Elements elements) {
  return ftxui::vbox(elements);
}

/* Wrapper for ftxui::hbox() */
inline Element HBox(Elements elements) {
  return ftxui::hbox(elements);
}

/* Wrapper for ftxui::text() */
inline Element Text(const String& displayString) {
  return ftxui::text(displayString);
}

Element drawTable() {
  Elements elementBuffer;

  elementBuffer.push_back(VBox({
    HBox({
      Text("Test text")
    })
  }));
 
  return elementBuffer;
}

// ftxui::Element drawFunction() {
//   std::Vector<ftxui::Element> windowContentVector;
//   ftxui::Element windowTitle = ftxui::text("What say?") | ftxui::bold;

//   windowContentVector.emplace_back(ftxui::text("Shashank da Superb") | ftxui::bold | ftxui::color(ftxui::Color::Green));
//   windowContentVector.emplace_back(ftxui::separator());
//   windowContentVector.emplace_back(ftxui::text("String1") | ftxui::border | ftxui::color(ftxui::Color::Yellow));
//   windowContentVector.emplace_back(ftxui::text("String2") | ftxui::border | ftxui::color(ftxui::Color::SkyBlue1));
//   windowContentVector.emplace_back(ftxui::text("String3") | ftxui::border | ftxui::color(ftxui::Color::Red));

//   ftxui::Element windowContent = ftxui::hbox({ftxui::vbox(windowContentVector)});
//   // ftxui::Element windowContent = ftxui::hbox(windowContentVector);

//   ftxui::Element window = ftxui::window(windowTitle, windowContent) | ftxui::border;
  
//   return window;
// }

int main() {
  ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();
  ftxui::Component renderer = ftxui::Renderer(drawTable);

  screen.Loop(renderer);
  
  return 0;
}