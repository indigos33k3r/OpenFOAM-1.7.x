/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 1991-2010 OpenCFD Ltd.
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Description

\*---------------------------------------------------------------------------*/

#include "error.H"
#include "LList.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class LListBase, class T>
Foam::LList<LListBase, T>::LList(const LList<LListBase, T>& lst)
:
    LListBase()
{
    for (const_iterator iter = lst.begin(); iter != lst.end(); ++iter)
    {
        append(iter());
    }
}


template<class LListBase, class T>
Foam::LList<LListBase, T>::~LList()
{
    this->clear();
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class LListBase, class T>
void Foam::LList<LListBase, T>::clear()
{
    label oldSize = this->size();
    for (label i=0; i<oldSize; i++)
    {
        removeHead();
    }

    LListBase::clear();
}


template<class LListBase, class T>
void Foam::LList<LListBase, T>::transfer(LList<LListBase, T>& lst)
{
    clear();
    LListBase::transfer(lst);
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class LListBase, class T>
void Foam::LList<LListBase, T>::operator=(const LList<LListBase, T>& lst)
{
    this->clear();

    for (const_iterator iter = lst.begin(); iter != lst.end(); ++iter)
    {
        append(iter());
    }
}


// * * * * * * * * * * * * * * * Friend Operators  * * * * * * * * * * * * * //

#include "LListIO.C"


// ************************************************************************* //
