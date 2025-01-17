#pragma once

#include <QButtonGroup>
#include <QFileSystemWatcher>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QStackedWidget>
#include <QTimer>
#include <QWidget>


#include "selfdrive/ui/qt/widgets/controls.h"

// ********** settings window + top-level panels **********

class DevicePanel : public QWidget {
  Q_OBJECT
public:
  explicit DevicePanel(QWidget* parent = nullptr);
signals:
  void reviewTrainingGuide();
  void showDriverView();
};

class TogglesPanel : public QWidget {
  Q_OBJECT
public:
  explicit TogglesPanel(QWidget *parent = nullptr);
};

class SoftwarePanel : public QFrame {
  Q_OBJECT
public:
  explicit SoftwarePanel(QWidget* parent = nullptr);

protected:
  void showEvent(QShowEvent *event) override;

private:
  QList<LabelControl *> labels;
  LabelControl *versionLbl;
  LabelControl *neosLbl;
  LabelControl *remoteLbl;
  LabelControl *branchLbl;
  LabelControl *commitLbl;
  LabelControl *lastUpdateTimeLbl;
  ButtonControl *updateButton;
  void updateLabels();

  QFileSystemWatcher *fs_watch;
};

class SettingsWindow : public QFrame {
  Q_OBJECT

public:
  explicit SettingsWindow(QWidget *parent = 0);

protected:
  void hideEvent(QHideEvent *event) override;
  void showEvent(QShowEvent *event) override;

signals:
  void closeSettings();
  void offroadTransition(bool offroad);
  void reviewTrainingGuide();
  void showDriverView();

private:
  QPushButton *sidebar_alert_widget;
  QWidget *sidebar_widget;
  QButtonGroup *nav_btns;
  QStackedWidget *panel_widget;
};
