#pragma once
#include "FilmeRepo.h"

class ActiuneUndo {
public:
	virtual void doUndo() = 0;
	virtual ~ActiuneUndo() = default;
};

class UndoAdauga : public ActiuneUndo {
	Film FilmAdaugat;
	FilmeRepo& repo;
public:
	UndoAdauga(FilmeRepo& repo, const Film& film) : repo{ repo }, FilmAdaugat{ film }{}

	void doUndo() override {
		repo.stergere(FilmAdaugat);
	}
};
class UndoSterge : public ActiuneUndo {
	Film FilmSters;
	FilmeRepo& repo;
public:
	UndoSterge(FilmeRepo& repo, const Film& film) : repo{ repo }, FilmSters{ film }{}

	void doUndo() override {
		repo.adauga(FilmSters);
	}
};
class UndoModifica : public ActiuneUndo {
	Film FilmModificat;
	FilmeRepo& repo;
public:
	UndoModifica(FilmeRepo& repo, const Film& film) : repo{ repo }, FilmModificat{ film }{}

	void doUndo() override {
		repo.modificare(FilmModificat);
	}
};