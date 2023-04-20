USE CinemaInAerLiber
GO

DROP TABLE Actor
CREATE TABLE Actor
(Aid INT PRIMARY KEY IDENTITY,
Nume VARCHAR(100),
Varsta INT
)

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

DROP TABLE film_actor
CREATE TABLE film_actor
(Fid INT FOREIGN KEY REFERENCES Film(Fid),
Aid INT FOREIGN KEY REFERENCES Actor(Aid),
CONSTRAINT pk_film_actor PRIMARY KEY(Fid,Aid)
)

GO
CREATE OR ALTER VIEW ViewProgram AS
SELECT * FROM Program

GO
CREATE OR ALTER VIEW ViewFilm AS
SELECT * FROM Film
GO
SELECT * FROM ViewFilm
GO
CREATE OR ALTER VIEW ViewFilmActor AS
SELECT a.Nume,a.Varsta,f.Gen FROM Actor a INNER JOIN film_actor fa ON a.Aid=fa.Aid INNER JOIN Film f ON fa.Fid=f.Fid WHERE a.Varsta<=30
GO
SELECT * FROM ViewFilmActor
GO

DROP TABLE Tables
INSERT INTO Tables VALUES ('Program'), ('Film'),('film_actor'),('Program'),('Film'),('film_actor')
DROP TABLE Views
INSERT INTO Views VALUES ('ViewProgram'),('ViewFilm'),('ViewFilmActor')
DROP TABLE Tests 
INSERT INTO Tests VALUES ('selectView'),('insertProgram'),('deleteProgram'),('insertFilm'),('deleteFilm'),('insertFilmActor'),('deleteFilmActor')

SELECT * FROM Tables 
SELECT * from Views
select * from Tests


DROP TABLE TestViews
INSERT INTO TestViews VALUES (1,1)
INSERT INTO TestViews VALUES (1,2)
INSERT INTO TestViews VALUES (1,3)

SELECT * FROM TestViews


DROP TABLE TestTables
INSERT INTO TestTables VALUES (2,1,100,1),(4,2,100,2),(6,3,100,3)

SELECT * FROM TestTables
GO

CREATE OR ALTER PROC insertProgram
AS
	DECLARE @crt INT = 1
	DECLARE @rows INT
	SELECT @rows = NoOfRows FROM TestTables WHERE TestID = 2
	PRINT @rows
	WHILE @crt <= @rows
	BEGIN
		INSERT INTO Program VALUES ('Luni',@crt)
		SET @crt = @crt + 1
	END
GO
--EXEC insertProgram
select * FROM Program
GO

CREATE OR ALTER PROC deleteProgram
AS
	DELETE FROM Program WHERE Pid > 0
	
GO
--EXEC deleteProgram

CREATE OR ALTER PROC insertFilm
AS
	DECLARE @crt INT = 1
	DECLARE @rows INT
	SELECT @rows = NoOfRows FROM TestTables WHERE TestID = 4
	PRINT @rows
	WHILE @crt <= @rows
	BEGIN
		INSERT INTO Film VALUES ('1h20min','comedie',@crt)
		SET @crt = @crt + 1
	END

GO
--EXEC insertFilm
select * from Film
GO
CREATE OR ALTER PROC deleteFilm
AS
	DELETE FROM Film WHERE Fid > 0

GO
--Exec deleteFilm



CREATE OR ALTER PROC insertFilmActor
AS
	DECLARE @crt INT = 1
	DECLARE @rows INT
	SELECT @rows = NoOfRows FROM TestTables WHERE TestID = 6
	PRINT @rows
	WHILE @crt <= @rows
	BEGIN
		INSERT INTO Actor VALUES ('Ana',20)
		INSERT INTO film_actor VALUES (@crt,@crt)
		SET @crt = @crt + 1
	END
GO


--EXEC insertFilmActor
select * FROM film_actor
GO
CREATE OR ALTER PROC deleteFilmActor
AS
	DELETE FROM Actor
	DELETE FROM film_actor

GO


CREATE OR ALTER PROC TestRunTablesProc
AS 
	DECLARE @start DATETIME;
	DECLARE @start1 DATETIME;
	DECLARE @start2 DATETIME;
	DECLARE @start3 DATETIME;
	DECLARE @start4 DATETIME;
	DECLARE @start5 DATETIME;
	DECLARE @start6 DATETIME;
	DECLARE @end1 DATETIME;
	DECLARE @end2 DATETIME;
	DECLARE @end3 DATETIME;
	DECLARE @end4 DATETIME;
	DECLARE @end5 DATETIME;
	DECLARE @end6 DATETIME;
	DECLARE @end DATETIME;
	DECLARE @description VARCHAR(100);
	SET @description = '';
	SET @start = GETDATE();
	EXEC deleteFilmActor;
	SET @description = @description +  'deleteFilmActor ';
	EXEC deleteFilm;
	SET @description = @description +  'deleteFilm ';
	EXEC deleteActor;
	SET @description = @description +  'deleteProgram ';
	
	
	SET @start4 = GETDATE();
	EXEC insertProgram;
	SET @description = @description +  'insertProgram ';
	SET @end4 = GETDATE();


	SET @start5 = GETDATE();
	EXEC insertFilm;
	SET @description = @description +  'insertFilm ';
	SET @end5 = GETDATE();
	--INSERT INTO TestRunTables VALUES (@@IDENTITY,5,@start5,@end5);
	
	SET @start6 = GETDATE();
	EXEC insertFilmActor;
	SET @description = @description +  'insertFilmActor ';
	SET @end6 = GETDATE();
	--INSERT INTO TestRunTables VALUES (@@IDENTITY,6,@start5,@end5);
	
	DECLARE @start1view DATETIME;
	DECLARE @start2view DATETIME;
	DECLARE @start3view DATETIME;
	DECLARE @end1view DATETIME;
	DECLARE @end2view DATETIME;
	DECLARE @end3view DATETIME;
	
	SET @start1view = GETDATE();
	EXEC ('SELECT * FROM ViewProgram');
	SET @description = @description +  'viewProgram ';
	SET @end1view = GETDATE();
    --INSERT INTO TestRunViews VALUES (@@IDENTITY, 1, @start1view, @end1view);

	SET @start2view = GETDATE();
	EXEC ('SELECT * FROM ViewFilm');
	SET @description = @description +  'viewFilm ';
	SET @end2view = GETDATE();
    --INSERT INTO TestRunViews VALUES (@@IDENTITY, 2, @start2view, @end2view);


	SET @start3view = GETDATE();
	EXEC ('SELECT * FROM ViewFilmActor');
	SET @description = @description +  'viewFilmActor ';
	SET @end3view = GETDATE();
    --INSERT INTO TestRunViews VALUES (@@IDENTITY, 3, @start3view, @end3view);

	SET @end = GETDATE();
	
	
	INSERT INTO TestRuns VALUES (@description,@start,@end)
	
	INSERT INTO TestRunTables VALUES(1,4,@start4,@end4);
	INSERT INTO TestRunTables VALUES(1,5,@start5,@end5);
	INSERT INTO TestRunTables VALUES(1,6,@start6,@end6);
	INSERT INTO TestRunViews VALUES (1, 1, @start1view, @end1view);
	INSERT INTO TestRunViews VALUES (1, 2, @start2view, @end2view);
	INSERT INTO TestRunViews VALUES (1, 3, @start3view, @end3view);
GO 

EXEC TestRunTablesProc;

SELECT * FROM Program
SELECT * FROM Film
SELECT * FROM film_actor

SELECT * FROM TestRuns
SELECT * FROM TestRunTables
SELECT * FROM TestRunViews

DROP TABLE TestRuns
DROP TABLE TestRunTables
DROP TABLE TestRunViews

