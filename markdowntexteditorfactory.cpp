#include "markdowntexteditorfactory.h"

#include <texteditor/textdocument.h>
#include <texteditor/texteditor.h>

#include <algorithm>
#include <typeinfo>

#include "markdowneditviewconstants.h"
#include "markdowntexteditorwidget.h"

namespace MarkdownEditView {
namespace Internal {

MarkdownTextEditorFactory::MarkdownTextEditorFactory() {
  setId(Constants::MARKDOWN_EDITOR_ID);
  setDisplayName("Markdown Edit & View");
  addMimeType("text/plain");
  addMimeType("text/markdown");

  setDocumentCreator([]() {
    return new TextEditor::TextDocument(Constants::MARKDOWN_EDITOR_ID);
  });
  setEditorCreator([]() { return new TextEditor::BaseTextEditor; });

  setEditorWidgetCreator(
      [=]() { return new MarkdownTextEditorWidget(htmlView); });
}

const QString MarkdownTextEditorFactory::getText() {
  TextEditor::TextEditorWidget* currentTexteditor =
      MarkdownTextEditorWidget::currentTextEditorWidget();
  if (currentTexteditor != nullptr &&
      typeid(*currentTexteditor) == typeid(MarkdownTextEditorWidget)) {
    return static_cast<MarkdownTextEditorWidget*>(currentTexteditor)
        ->document()
        ->toPlainText();
  } else {
    return QString();
  }
};
}  // namespace Internal
}  // namespace MarkdownEditView
