--DROP DATABASE CinemaInAerLiber
CREATE DATABASE CinemaInAerLiber
GO
use CinemaInAerLiber
GO

DROP TABLE Program
CREATE TABLE Program
(Pid INT PRIMARY KEY IDENTITY,
Zi VARCHAR(50),
nrFilme INT
)

DROP TABLE Film
CREATE TABLE Film
(Fid INT PRIMARY KEY IDENTITY,
Durata VARCHAR(50),
Gen VARCHAR(100),
Pid INT FOREIGN KEY REFERENCES Program(Pid)
)

DROP TABLE Spectatori
CREATE TABLE Spectatori
(Sid INT PRIMARY KEY IDENTITY,
Nume VARCHAR(100),
NrTel VARCHAR(100),
Email VARCHAR(100)
)

DROP TABLE Bilet
CREATE TABLE Bilet
(Bid INT PRIMARY KEY IDENTITY,
Ora_inceput TIME,
Ora_sfarsit TIME,
Loc INT CHECK(Loc<=200),
Fid INT FOREIGN KEY REFERENCES Film(Fid),
Sid INT FOREIGN KEY REFERENCES Spectatori(Sid)
)

DROP TABLE Actor
CREATE TABLE Actor
(Aid INT PRIMARY KEY IDENTITY,
Nume VARCHAR(100),
Varsta INT
)

DROP TABLE film_actor
CREATE TABLE film_actor
(Fid INT FOREIGN KEY REFERENCES Film(Fid),
Aid INT FOREIGN KEY REFERENCES Actor(Aid),
CONSTRAINT pk_film_actor PRIMARY KEY(Fid,Aid)
)

DROP TABLE Tara
CREATE TABLE Tara 
(Tid INT PRIMARY KEY IDENTITY,
nrLimbi INT
)

DROP TABLE Limba
CREATE TABLE Limba
(Lid INT PRIMARY KEY IDENTITY,
Denumire VARCHAR(100),
Tid INT FOREIGN KEY REFERENCES Tara(Tid)
)

DROP TABLE actor_limba
CREATE TABLE actor_limba
(Aid INT FOREIGN KEY REFERENCES Actor(Aid),
Lid INT FOREIGN KEY REFERENCES Limba(Lid),
CONSTRAINT pk_actor_limba PRIMARY KEY(Aid,Lid)
)

DROP TABLE Snacks
CREATE TABLE Snacks
(SnackId INT PRIMARY KEY IDENTITY,
Denumire VARCHAR(100),
Pret FLOAT,
Sid INT FOREIGN KEY REFERENCES Spectatori(Sid)
)



INSERT INTO Program(Zi,nrFilme)
VALUES('Luni','7')
INSERT INTO Program(Zi,nrFilme)
VALUES('Marti','10')
INSERT INTO Program(Zi,nrFilme)
VALUES('Miercuri','5')
INSERT INTO Program(Zi,nrFilme)
VALUES('Joi','4')
INSERT INTO Program(Zi,nrFilme)
VALUES('Vineri','8')

INSERT INTO Film(Durata,Gen,Pid)
VALUES('1h20min','Actiune',2),('2h15min','Comedie',3),('1h45min','Horror',1),('2h8min','Dragoste',2)

INSERT INTO Spectatori(Nume,NrTel,Email)
VALUES('Popescu Ioan','0770456789','popescu.ioan@yahoo.com'),('Popa Alina','0755436219','popa.alina@gmail.com'),('Dan Andrei','0722436901','danandrei@yahoo.com')

INSERT INTO Bilet(Ora_inceput,Ora_sfarsit,Loc,Fid,Sid)
VALUES('22:00:00','23:30:00',30,1,1),('12:00:00','14:35:00',8,3,2),('18:30:00','20:10:00',8,1,3)

INSERT INTO Actor(Nume,Varsta)
VALUES('Alina',23),('Filip',40),('Andreea',34),('Sergiu',27)
SELECT * FROM Actor

INSERT INTO film_actor(Fid,Aid)
VALUES(1,2),(3,4),(4,2),(2,1)

INSERT INTO Tara(nrLimbi)
VALUES (2),(3),(1),(4)

INSERT INTO Limba(Denumire,Tid)
VALUES('Engleza',1),('Romana',1),('Spaniola',2),('Franceza',3),('Germana',4)

INSERT INTO actor_limba(Aid,Lid)
VALUES(1,3),(2,4),(2,1),(2,2),(4,5)

INSERT INTO Snacks(Denumire,Pret,Sid)
VALUES('Popcorn cu sare',11.50,1),('Popcorn cu unt',12,3),('Nachos',20,2)


INSERT INTO Snacks(Denumire,Pret,Sid)
VALUES ('Nachos',33,1)

SELECT * FROM Program
SELECT * FROM Film
SELECT * FROM Bilet
SELECT * FROM film_actor
SELECT * FROM actor_limba
SELECT * FROM Snacks

--returneaza numarul filmelor din programul de luni
SELECT SUM(p.nrFilme) AS Filmele_de_luni from Program p INNER JOIN Film f ON p.Pid=f.Pid WHERE p.Zi='Luni' GROUP BY p.nrFilme HAVING p.nrFilme=7

--returneaza locurile distincte cu valoarea cuprinsa intre 1 si 50
SELECT DISTINCT b.Loc from Film f INNER JOIN Bilet b ON f.Fid=b.Fid WHERE b.Loc BETWEEN 1 AND 50

--returneaza numele spectatorilor care incep cu litera "P", emailul si ora de pe bilet
SELECT s.Nume, s.Email, b.Ora_inceput AS Ora FROM Spectatori s INNER JOIN Bilet b on s.Sid=b.Sid WHERE s.Nume LIKE 'P%'

--returneaza numele si varsta actorilor mai mici de 30 de ani si genul filmului in care joaca
SELECT a.Nume,a.Varsta,f.Gen FROM Actor a INNER JOIN film_actor fa ON a.Aid=fa.Aid INNER JOIN Film f ON fa.Fid=f.Fid WHERE a.Varsta<=30

--returneaza denumirea limbii si tara de origine care are mai mult de o limba
SELECT l.Denumire,t.nrLimbi FROM Limba l INNER JOIN Tara t ON l.Tid=t.Tid GROUP BY Denumire,nrLimbi HAVING t.nrLimbi>1 

--returneaza numele actorilor care contin litera "i" ,varsta acestora si limba vorbita
SELECT a.Nume,a.Varsta,l.Denumire FROM Actor a INNER JOIN actor_limba al ON a.Aid=al.Aid INNER JOIN Limba l ON al.Lid=l.Lid WHERE a.Nume LIKE '%i%'

--returneaza denumirile distincte ale snacksurilor
SELECT DISTINCT Denumire FROM Snacks GROUP BY Denumire

--returneaza emailul si locul spectatorilor
SELECT s.Email,b.Loc FROM Spectatori s INNER JOIN Bilet b ON s.Sid=b.Sid

--returneaza noul pret rezultat din dublul celui vechi pentru snacksuri si numele spectatorilor ce le-au cumparat
SELECT Pret_nou=snack.Pret*2,s.Nume FROM Spectatori s INNER JOIN Snacks snack ON s.Sid=snack.Sid

--returneaza denumirea limbii si noul numar de limbi vorbite intr-o tara
SELECT l.Denumire,NrLimbi_Nou=t.nrLimbi+1 FROM Limba l INNER JOIN Tara t ON l.Tid=t.Tid

