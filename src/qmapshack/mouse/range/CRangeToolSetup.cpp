/**********************************************************************************************
    Copyright (C) 2018 Oliver Eichler <oliver.eichler@gmx.de>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

**********************************************************************************************/

#include "mouse/range/CRangeToolSetup.h"

#include <QtWidgets>

#include "mouse/range/CScrOptRangeTool.h"

CRangeToolSetup::CRangeToolSetup(CScrOptRangeTool& parent) : QDialog(&parent), tool(parent) {
  setupUi(this);

  actionsHidePoints->setAction(tool.actionHidePoints);
  actionsShowPoints->setAction(tool.actionShowPoints);
  actionsActivity->setAction(tool.actionActivity);
  actionsCopy->setAction(tool.actionCopy);
  actionsDelete->setAction(tool.actionDelete);

  checkMoveMap->setChecked(tool.enableUpdateCavas);
}

void CRangeToolSetup::accept() {
  tool.actionHidePoints = actionsHidePoints->getAction();
  tool.actionShowPoints = actionsShowPoints->getAction();
  tool.actionActivity = actionsActivity->getAction();
  tool.actionCopy = actionsCopy->getAction();
  tool.actionDelete = actionsDelete->getAction();

  tool.enableUpdateCavas = checkMoveMap->isChecked();

  QDialog::accept();
}
