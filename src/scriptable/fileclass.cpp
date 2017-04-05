/*
    Copyright (c) 2017, Lukas Holecek <hluk@email.cz>

    This file is part of CopyQ.

    CopyQ is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    CopyQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with CopyQ.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "fileclass.h"

#include <QDir>

COPYQ_DECLARE_SCRIPTABLE_CLASS(FileClass)

FileClass::FileClass(QScriptEngine *engine)
    : ScriptableClass(engine)
{
}

QScriptValue FileClass::newInstance(const QString &path)
{
    return ScriptableClass::newInstance( new QFile(QDir(m_currentPath).absoluteFilePath(path)) );
}

QScriptValue FileClass::newInstance()
{
    return ScriptableClass::newInstance( new QFile() );
}

const QString &FileClass::getCurrentPath() const
{
    return m_currentPath;
}

void FileClass::setCurrentPath(const QString &path)
{
    m_currentPath = path;
}

QScriptValue FileClass::createInstance(const QScriptContext &context)
{
    return context.argumentCount() > 0
            ? newInstance(context.argument(0).toString())
            : newInstance();
}
