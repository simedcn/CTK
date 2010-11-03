/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.commontk.org/LICENSE

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

#ifndef __ctkColorPickerButton_h
#define __ctkColorPickerButton_h

// Qt includes
#include <QPushButton>
#include <QColor>

// CTK includes
#include "ctkWidgetsExport.h"
class ctkColorPickerButtonPrivate;

///
/// ctkColorPickerButton is a QPushButton that refers to a color. The color 
/// and the name of the color (i.e. #FFFFFF) are displayed on the button.
/// When clicked, a color dialog pops up to select a new color 
/// for the QPushButton.
class CTK_WIDGETS_EXPORT ctkColorPickerButton : public QPushButton
{
  Q_OBJECT
  Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged USER true)
  Q_PROPERTY(bool displayColorName READ displayColorName WRITE setDisplayColorName DESIGNABLE true)
  Q_PROPERTY(bool showAlpha READ showAlpha WRITE setShowAlpha DESIGNABLE true)
public:
  /// By default, the color is black
  explicit ctkColorPickerButton(QWidget* parent = 0);
  /// By default, the color is black. The text will be shown on the button if
  /// displayColorName is false, otherwise the color name is shown.
  /// \sa QPushButton::setText
  explicit ctkColorPickerButton(const QString& text, QWidget* parent = 0 );
  /// The text will be shown on the button if
  /// displayColorName is false, otherwise the color name is shown.
  /// \sa setColor, QPushButton::setText 
  explicit ctkColorPickerButton(const QColor& color, const QString & text, QWidget* parent = 0 );
  virtual ~ctkColorPickerButton();
 
  ///
  /// Current selected color
  QColor color()const;

  ///
  /// Display the color name after color selection
  bool displayColorName()const;
  
  ///
  /// Returns true if alpha is shown on the color dialog
  /// \sa QColorDialog::ShowAlphaChannel
  void setShowAlpha(bool show);
  bool showAlpha()const;

public slots:
  ///
  /// Set a new current color without opening a dialog
  void setColor(const QColor& color);

  /// 
  /// Opens a color dialog to select a new current color.
  void changeColor();

  ///
  /// Toggle the display of the color name after color selection.
  /// By default, this is activated.
  void setDisplayColorName(bool displayColorName);

signals:
  /// colorChanged is fired anytime a new color is set. Programatically or
  /// by the user when choosing a color from the color dialog
  void colorChanged(QColor);

protected slots:
  void onToggled(bool change = true);

protected:
  virtual void paintEvent(QPaintEvent* event);

  QScopedPointer<ctkColorPickerButtonPrivate> d_ptr;
private :
  Q_DECLARE_PRIVATE(ctkColorPickerButton);
  Q_DISABLE_COPY(ctkColorPickerButton);
};

#endif
