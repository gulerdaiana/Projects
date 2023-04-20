USE CinemaInAerLiber
GO

DROP TABLE Actor
CREATE TABLE Actor
(Aid INT PRIMARY KEY IDENTITY,
Nume VARCHAR(100),
Varsta INT
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
Create function dbo.TestVarsta(@varsta int)
RETURNS INT
AS
BEGIN
IF @varsta>18  SET @varsta = 1
ELSE SET @varsta = 0
RETURN @varsta
END
go

Create function dbo.TestGen(@gen VARCHAR(100))
RETURNS INT
AS
BEGIN
IF @gen='Actiune' OR @gen='Comedie' OR @gen='Horror' OR @gen='Dragoste'  SET @gen = 1
ELSE SET @gen = 0
RETURN @gen
END


GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

create or alter procedure CRUD_Actor
@table_name Varchar(50),
@nume varchar(100),
@varsta int
AS
BEGIN
	SET NOCOUNT ON;
	-- verify the parameters - at least one from the list
	IF (dbo.TestVarsta(@varsta)=1)
	BEGIN
		--CREATE=INSERT
		insert into Actor(Nume, Varsta) Values(@nume, @varsta)
		-- READ=SELECT
		select * from Actor
		-- UPDATE
		update Actor set Varsta='30'
		where Varsta>18 and Nume LIKE 'A%'
		-- DELETE
		delete from film_actor
		delete from Actor
		where Varsta < 20
		print 'CRUD operations for table ' + @table_name
		END
	ELSE
	BEGIN
		PRINT 'Error'
		RETURN
	END
END
go

EXEC CRUD_Actor 'Actor', 'Ana', 25
go
EXEC CRUD_Actor 'Actor', 'Ana', -3
go


create or alter procedure CRUD_Film
@table_name Varchar(50),
@durata varchar(50),
@gen VARCHAR(100)
AS
BEGIN
	SET NOCOUNT ON;
	-- verify the parameters - at least one from the list
	IF (dbo.TestGen(@gen)=1)
	BEGIN
		--CREATE=INSERT
		declare @pid int
		SELECT TOP 1 @pid = Pid FROM dbo.Program
		insert into Film(Durata,Gen,Pid) Values(@durata, @gen,@pid)
		-- READ=SELECT
		select * from Film
		-- UPDATE
		update Film set Durata='1h30min'
		where Gen LIKE 'C%'
		-- DELETE
		delete from film_actor
        delete from Bilet
		delete from Film
		where Gen = 'Horror'
		print 'CRUD operations for table ' + @table_name
		END
	ELSE
	BEGIN
		PRINT 'Error'
		RETURN
	END
END
go

EXEC CRUD_Film 'Film', '1h20min','Comedie' --EXECUTIE CU SUCCES
go

EXEC CRUD_Film 'Film', '1h40min','SciFi'  --EXECUTIE FARA SUCCES -> ERROR
go

create or alter procedure CRUD_FilmActor
@table_name Varchar(50)
AS
BEGIN
	SET NOCOUNT ON;
	-- verify the parameters - at least one from the list
	BEGIN
		--CREATE=INSERT
		--insert into film_actor(Fid, Aid) values ('4','4')
		--insert into film_actor(Fid, Aid) values ('2','2')
		declare @fid int
		SELECT TOP 1 @fid = Fid FROM dbo.Film
		declare @aid int
		SELECT TOP 1 @aid = Aid FROM dbo.Actor
		--insert into film_actor(Fid,Aid) Values(@fid, @aid)
		-- READ=SELECT
		select * from film_actor
		-- UPDATE
		update film_actor set Fid='100'
		where Aid LIKE '5'
		-- DELETE
		delete from film_actor
		where Fid = 4
		print 'CRUD operations for table ' + @table_name
		END
END

EXEC CRUD_FilmActor 'FilmActor'
go

CREATE VIEW vw_Film 
AS
SELECT f.Fid
FROM  Film f
where f.Fid > 1;
go


select * from Film
select * from Actor
go


create or alter VIEW vw_Actor_FilmActor
AS
SELECT a.Nume
FROM  Actor a inner join film_actor fa on a.Aid = fa.Aid
where a.Nume like 'A%';

go

go
create or alter VIEW vw_Actor_FilmActor2
AS
SELECT a.Nume
FROM  Actor a inner join film_actor fa on a.Aid = fa.Aid

go

select * from  vw_Film				
select * from  vw_Actor_FilmActor
select * from  vw_Actor_FilmActor2


IF EXISTS (SELECT NAME FROM sys.indexes WHERE name='N_idx_film_fid')
DROP INDEX N_idx_film_fid ON Film
CREATE NONCLUSTERED INDEX N_idx_film_fid ON Film (Fid)

select * from vw_Film		--PRIMUL BUN

go
IF EXISTS (SELECT NAME FROM sys.indexes WHERE name='N_idx_actor_filmactor_aid_nume')
DROP INDEX N_idx_actor_filmactor_aid_nume ON Actor
CREATE NONCLUSTERED INDEX N_idx_actor_filmactor_aid_nume ON Actor (Nume)
select * from Program
insert into Actor(Nume,Varsta) Values('Maria', 27), ('Daniel',41), ('Dana',22),('Alexandra',36)
select * from Actor
insert into Film(Durata,Gen,Pid) Values('1h45min', 'Actiune','4'), ('2h20min','Horror','2'), ('2h10min','Dragoste','3'),('1h55min','Comedie','1')
select * from Actor
select * from Film
insert into film_actor(Fid, Aid) values ('1004','1002'), ('1005','1003'), ('1007','1004')
SELECT * FROM vw_Actor_FilmActor

go
--AL DOILEA BUN
IF EXISTS (SELECT NAME FROM sys.indexes WHERE name='N_idx_actor_filmactor_aid_nume2')
DROP INDEX N_idx_actor_filmactor_aid_nume2 ON Actor
CREATE NONCLUSTERED INDEX N_idx_actor_filmactor_aid_nume2 ON film_actor (Aid)
select * from  vw_Actor_FilmActor2