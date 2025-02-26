/*
 * Copyright (C) 2021 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef KSNIP_ACTIONSETTINGTAB_H
#define KSNIP_ACTIONSETTINGTAB_H

#include <QWidget>
#include <QGridLayout>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "src/common/helper/EnumTranslator.h"
#include "src/widgets/CustomSpinBox.h"
#include "src/widgets/CustomLineEdit.h"
#include "src/widgets/KeySequenceLineEdit.h"
#include "src/gui/actions/Action.h"

class ActionSettingTab : public QWidget
{
	Q_OBJECT
public:
	explicit ActionSettingTab(const QString &name, const QList<CaptureModes> &captureModes);
	explicit ActionSettingTab(const Action &action, const QList<CaptureModes> &captureModes);
	~ActionSettingTab() override;
	Action action() const;

signals:
	void nameChanged(const QString &name);

protected:
	explicit ActionSettingTab(const QList<CaptureModes> &captureModes);
	void setAction(const Action &action) const;

private:
	QComboBox *mCaptureModeComboBox;
	QCheckBox *mCaptureEnabledCheckBox;
	QCheckBox *mIncludeCursorCheckBox;
	QCheckBox *mShowPinWindowCheckBox;
	QCheckBox *mUploadCheckBox;
	QCheckBox *mSaveCheckBox;
	QCheckBox *mCopyToClipboardCheckBox;
	QCheckBox *mOpenDirectoryCheckBox;
	QCheckBox *mHideMainWindowCheckBox;
	QLabel *mCaptureModeLabel;
	QLabel *mDelayLabel;
	QLabel *mNameLabel;
	QLabel *mShortcutLabel;
	CustomSpinBox *mDelaySpinBox;
	CustomLineEdit *mNameLineEdit;
	KeySequenceLineEdit *mShortcutLineEdit;
	QPushButton *mShortcutClearButton;
	QGridLayout *mLayout;

	void initGui(const QList<CaptureModes> &captureModes);
	void populateCaptureModeCombobox(const QList<CaptureModes> &captureModes);
	int indexOfSelectedCaptureMode(CaptureModes modes) const;
	static QString getTextWithEscapedAmpersand(const QString &text);
	static QString getTextWithoutEscapedAmpersand(const QString &text);

private slots:
	void captureEnabledChanged();
	void nameEditingFinished();
};

#endif //KSNIP_ACTIONSETTINGTAB_H
