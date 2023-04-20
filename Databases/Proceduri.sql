CREATE TABLE Version(VersionNo INT)
INSERT INTO Version VALUES(0)
SELECT * FROM Version

--modifica tipul unei coloane
GO
CREATE OR ALTER PROCEDURE modifNrFilmeNotNull AS
ALTER TABLE Program 
ALTER COLUMN nrFilme INT NOT NULL 
print 'S-a modificat tipul coloanei nrFilme in NOT NULL'

--undo modificare

GO
CREATE OR ALTER PROCEDURE modifNrFilmeInt AS
ALTER TABLE Program 
ALTER COLUMN nrFilme INT
print 'S-a modificat tipul coloanei nrFilme inapoi in INT'

--adaugare constrangere default
GO
CREATE OR ALTER PROCEDURE addConstraintVarsta AS
ALTER TABLE Actor ADD CONSTRAINT defaultVarsta default(30) FOR Varsta
print 'S-a adaugat constrangerea default 30 pentru varsta actorilor'

--undo adaugare de constrangere default

GO
CREATE OR ALTER PROCEDURE removeConstraintVarsta AS
ALTER TABLE Actor DROP CONSTRAINT defaultVarsta
print 'S-a sters constrangerea default 30 pentru varsta actorilor'
--creare tabel nou

GO
CREATE OR ALTER PROCEDURE addTable AS
    CREATE TABLE Angajat(
        Anid INT PRIMARY KEY IDENTITY,
        NumeAngajat VARCHAR(100),
        Departament VARCHAR(100),
        Pid INT
    )
print 'S-a creat tabelul Angajat'

-- stergerea tabelului
GO
CREATE OR ALTER PROCEDURE removeTable AS 
DROP TABLE Angajat
print 'S-a sters tabelul Angajat'

-- adaugare de coloana
GO
CREATE OR ALTER PROCEDURE addColoana AS
ALTER TABLE Angajat ADD Salar INT
print 'S-a adaugat coloana Salar in tabelul Angajat'

-- stergere coloana
GO 
CREATE OR ALTER PROCEDURE removeColoana AS
ALTER TABLE Angajat DROP COLUMN Salar
print 'S-a sters coloana Salar din tabelul Angajat'

--  adaugare constrangere cheie straina
GO
CREATE OR ALTER PROCEDURE addfk AS
ALTER TABLE Angajat ADD CONSTRAINT fk_Angajat FOREIGN KEY(Pid) REFERENCES Program(Pid)
print 'S-a adaugat constrangerea de cheie straina in tabelul Angajat'

--stergere constrangere cheie straina
GO
CREATE OR ALTER PROCEDURE removefk AS
ALTER TABLE Angajat DROP CONSTRAINT fk_Angajat
print 'S-a sters constrangerea de cheie straina in tabelul Angajat'

GO
DROP TABLE ProcedureTable
CREATE TABLE ProcedureTable(
    fromVersion INT,
    toVersion INT,
    PRIMARY KEY(fromVersion, toVersion),
    storedProcedure VARCHAR(100)
)
GO
INSERT INTO ProcedureTable VALUES(0,1,'modifNrFilmeNotNull')
INSERT INTO ProcedureTable VALUES(1,0,'modifNrFilmeInt')
INSERT INTO ProcedureTable VALUES(1,2,'addConstraintVarsta')
INSERT INTO ProcedureTable VALUES(2,1,'removeConstraintVarsta')
INSERT INTO ProcedureTable VALUES(2,3,'addTable')
INSERT INTO ProcedureTable VALUES(3,2,'removeTable')
INSERT INTO ProcedureTable VALUES(3,4,'addColoana')
INSERT INTO ProcedureTable VALUES(4,3,'removeColoana')
INSERT INTO ProcedureTable VALUES(4,5,'addfk')
INSERT INTO ProcedureTable VALUES(5,4,'removefk')

go
create procedure main
    @wantedVersion tinyint
as
begin
    declare @vers tinyint
    set @vers = (select versionNo from Version)


	 if(@wantedVersion < 0 OR @wantedVersion > 5) begin
        print('Versiunea trebuie sa fie un numar intre 0 si 5!')
        goto SKIPPER
    end

    while(@vers < @wantedVersion)
    begin
        if(@vers = 0) begin
            exec modifNrFilmeNotNull
        end
        if(@vers = 1) begin
            exec addConstraintVarsta
        end
        if(@vers = 2) begin
            exec addTable
        end
        if(@vers = 3) begin
            exec addColoana
        end
        if(@vers = 4) begin
            exec addfk
        end
        set @vers = @vers +1;
    end

    while(@vers > @wantedVersion)
    begin
        if(@vers = 5) begin
            exec removefk
        end
        if(@vers = 4) begin
            exec removeColoana
        end
        if(@vers = 3) begin
            exec removeTable
        end
        if(@vers = 2) begin
            exec removeConstraintVarsta
        end
        if(@vers = 1) begin
            exec modifNrFilmeInt
        end
        set @vers = @vers -1;
    end

    if(@vers = @wantedVersion)
    begin
        print 'Baza de date a fost adusa la versiunea dorita!'
        update Version
        set VersionNo = @vers
    end

    skipper:
end
go
select * from Version
execute main 2
select * from ProcedureTable

DROP PROCEDURE modifNrFilmeNotNull
DROP PROCEDURE modifNrFilmeInt
DROP PROCEDURE addConstraintVarsta
DROP PROCEDURE removeConstraintVarsta
DROP PROCEDURE addTable
DROP PROCEDURE removeTable
DROP PROCEDURE addColoana
DROP PROCEDURE removeColoana
DROP PROCEDURE addfk
DROP PROCEDURE removefk
select * from dbo.Angajat