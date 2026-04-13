CREATE TABLE filme (
    id_film INT PRIMARY KEY,
    titlu VARCHAR2(255) NOT NULL,
    gen VARCHAR2(100),
    durata INT CHECK (durata > 0),
    regizor VARCHAR2(255)
);

CREATE TABLE actori (
    id_actor INT PRIMARY KEY,
    nume VARCHAR2(255) NOT NULL,
    varsta INT CHECK (varsta > 0),
    nationalitate VARCHAR2(100)
);

CREATE TABLE filme_actori (
    id_film INT,
    id_actor INT,
    PRIMARY KEY (id_film, id_actor),
    FOREIGN KEY (id_film) REFERENCES filme(id_film),
    FOREIGN KEY (id_actor) REFERENCES actori(id_actor)
);

CREATE TABLE spectatori (
    id_spectator INT PRIMARY KEY,
    nume VARCHAR2(255) NOT NULL,
    email VARCHAR2(255) UNIQUE,
    telefon VARCHAR2(20)
);

CREATE TABLE bilete (
    id_bilet INT PRIMARY KEY,
    id_spectator INT,
    id_film INT,
    pret INT CHECK (pret > 0),
    FOREIGN KEY (id_spectator) REFERENCES spectatori(id_spectator),
    FOREIGN KEY (id_film) REFERENCES filme(id_film)
);

COMMIT; 
DROP TABLE filme_actori;
DROP TABLE bilete;
DROP TABLE spectatori;
DROP TABLE filme;
DROP TABLE actori;

-- Indexul pe coloana "titlu" din tabelul "filme" ajuta la filtrarea mai rapida a tabelului la cautare
CREATE INDEX idx_filme_titlu ON filme(titlu);

-- Indexul pe coloana "nume" din tabelul "actori" ajuta la filtrarea mai rapida a tabelului la cautare
CREATE INDEX idx_actori_nume ON actori(nume);

-- Indexul pe coloana 'pret' din tabelul 'bilete' ajuta la filtrarea si sortarea biletelor dupa pret
CREATE INDEX idx_bilete_pret ON bilete(pret);

-- INSERT, UPDATE, DELETE 
-- Insert
INSERT INTO filme VALUES (1, 'Inception', 'Sci-Fi', 148, 'Christopher Nolan');
INSERT INTO filme VALUES (2, 'Interstellar', 'Sci-Fi', 169, 'Christopher Nolan');
INSERT INTO filme VALUES (3, 'The Dark Knight', 'Action', 152, 'Christopher Nolan');
INSERT INTO filme VALUES (4, 'Titanic', 'Drama', 195, 'James Cameron');
INSERT INTO filme VALUES (5, 'Avatar', 'Fantasy', 162, 'James Cameron');
INSERT INTO filme VALUES (6, 'Pulp Fiction', 'Crime', 154, 'Quentin Tarantino');
INSERT INTO filme VALUES (7, 'The Matrix', 'Sci-Fi', 136, 'Lana Wachowski, Lilly Wachowski');
INSERT INTO filme VALUES (8, 'Fight Club', 'Drama', 139, 'David Fincher');
INSERT INTO filme VALUES (9, 'Forrest Gump', 'Drama', 142, 'Robert Zemeckis');
INSERT INTO filme VALUES (10, 'The Godfather', 'Crime', 175, 'Francis Ford Coppola');




INSERT INTO spectatori (id_spectator, nume, email, telefon) 
VALUES (1, 'Maria Ionescu', 'maria.ionescu@email.com', '0722334455');

INSERT INTO spectatori (id_spectator, nume, email, telefon) 
VALUES (2, 'Ion Popescu', 'ion.popescu@email.com', '0722334466');

INSERT INTO spectatori (id_spectator, nume, email, telefon) 
VALUES (3, 'Ana Georgescu', 'ana.georgescu@email.com', '0722334477');

INSERT INTO spectatori (id_spectator, nume, email, telefon) 
VALUES (4, 'Andrei Vasile', 'andrei.vasile@email.com', '0722334488');

INSERT INTO spectatori (id_spectator, nume, email, telefon) 
VALUES (5, 'Elena Dumitru', 'elena.dumitru@email.com', '0722334499');

INSERT INTO spectatori (id_spectator, nume, email, telefon) 
VALUES (6, 'Marian Ionescu', 'marian.ionescu@email.com', '0722334400');

INSERT INTO spectatori (id_spectator, nume, email, telefon) 
VALUES (7, 'Ioana Păunescu', 'ioana.paunescu@email.com', '0722334411');

INSERT INTO spectatori (id_spectator, nume, email, telefon) 
VALUES (8, 'Victor Nistor', 'victor.nistor@email.com', '0722334422');

INSERT INTO spectatori (id_spectator, nume, email, telefon) 
VALUES (9, 'Mihai Radu', 'mihai.radu@email.com', '0722334433');

INSERT INTO spectatori (id_spectator, nume, email, telefon) 
VALUES (10, 'Gabriela Stoica', 'gabriela.stoica@email.com', '0722334444');






INSERT INTO bilete (id_bilet, id_spectator, id_film, pret) 
VALUES (1, 1, 1, 45);

INSERT INTO bilete (id_bilet, id_spectator, id_film, pret) 
VALUES (2, 1, 2, 60);

INSERT INTO bilete (id_bilet, id_spectator, id_film, pret) 
VALUES (3, 2, 3, 50);

INSERT INTO bilete (id_bilet, id_spectator, id_film, pret) 
VALUES (4, 3, 4, 80);

INSERT INTO bilete (id_bilet, id_spectator, id_film, pret) 
VALUES (5, 4, 5, 75);

INSERT INTO bilete (id_bilet, id_spectator, id_film, pret) 
VALUES (6, 5, 6, 55);

INSERT INTO bilete (id_bilet, id_spectator, id_film, pret) 
VALUES (7, 6, 7, 40);

INSERT INTO bilete (id_bilet, id_spectator, id_film, pret) 
VALUES (8, 7, 8, 65);

INSERT INTO bilete (id_bilet, id_spectator, id_film, pret) 
VALUES (9, 8, 9, 70);

INSERT INTO bilete (id_bilet, id_spectator, id_film, pret) 
VALUES (10, 9, 10, 85);


INSERT INTO actori VALUES (1, 'Matthew McConaughey', 54, 'American');
INSERT INTO filme_actori VALUES (1, 1);


Select * from filme;
Select * from actori;
Select * from filme_actori;
Select * from spectatori;
Select * from bilete;

-- Update
UPDATE filme SET durata = 150 WHERE id_film = 1;
UPDATE spectatori SET email = 'maria.new@email.com' WHERE id_spectator = 1;

-- Delete
DELETE FROM bilete WHERE id_bilet = 1;
DELETE FROM filme_actori WHERE id_film = 1;
DELETE FROM spectatori;


--Operatii invalide
-- durata negativa
INSERT INTO filme VALUES (3, 'Avatar', 'Fantasy', -162, 'James Cameron');

-- Id actor invalid
INSERT INTO filme_actori VALUES (1, 99);

-- email duplicat
INSERT INTO spectatori VALUES (2, 'Maria Popescu', 'maria.new@email.com', '0733445566');



--view sistem

CREATE VIEW v_tabele_definite AS
SELECT table_name FROM user_tables;

SELECT * FROM v_tabele_definite;

CREATE VIEW v_restrictii_definite AS
SELECT table_name, constraint_name, constraint_type FROM user_constraints WHERE table_name IN ('FILME', 'ACTORI', 'BILETE');

SELECT * FROM v_restrictii_definite;

CREATE VIEW v_indexuri AS
SELECT index_name, table_name, column_name FROM user_ind_columns WHERE table_name IN ('FILME', 'ACTORI', 'BILETE');

SELECT * FROM v_indexuri;

CREATE VIEW v_coloane_filme AS
SELECT column_name, data_type FROM user_tab_columns WHERE table_name = 'FILME';

SELECT * FROM v_coloane_filme;



--procedura de filtrare cu interval

SET SERVEROUTPUT ON;

CREATE OR REPLACE PROCEDURE select_filtered_bilete(p IN INT) AS
    CURSOR c_bilete IS
        SELECT id_bilet, id_spectator, id_film, pret
        FROM bilete
        WHERE pret BETWEEN (50 - p / 2) AND (50 + p / 2)
        ORDER BY pret DESC;

    v_id_bilet bilete.id_bilet%TYPE;
    v_id_spectator bilete.id_spectator%TYPE;
    v_id_film bilete.id_film%TYPE;
    v_pret bilete.pret%TYPE;
    v_total_rows INT;
    v_limit_rows INT;
BEGIN
    -- Calculăm numărul total de înregistrări care corespund condiției
    SELECT COUNT(*) INTO v_total_rows FROM bilete
    WHERE pret BETWEEN (50 - p / 2) AND (50 + p / 2);
    
    -- Calculăm numărul de înregistrări care trebuie afișate pe baza procentajului p
    v_limit_rows := ROUND((v_total_rows * p) / 100);

    -- Deschidem cursorul pentru selectarea înregistrărilor
    OPEN c_bilete;
    
    -- Loop over cursor
    FOR i IN 1..v_limit_rows LOOP
        EXIT WHEN c_bilete%NOTFOUND;  -- Move this before FETCH
        FETCH c_bilete INTO v_id_bilet, v_id_spectator, v_id_film, v_pret;
        
        -- Afișăm rezultatele 
        DBMS_OUTPUT.PUT_LINE('ID Bilet: ' || v_id_bilet || 
                             ', ID Spectator: ' || v_id_spectator || 
                             ', ID Film: ' || v_id_film || 
                             ', Pret: ' || v_pret);
    END LOOP;
    
    CLOSE c_bilete;
END select_filtered_bilete;
/

BEGIN
    select_filtered_bilete(30);  -- Afișează 30% dintre înregistrările cu prețul între 50 - p/2 și 50 + p/2
END;



--view cu lista procedurilor

CREATE VIEW user_procedures AS
SELECT owner, object_name FROM all_procedures WHERE owner = USER;

SELECT * FROM user_procedures;

--procedura pt a returna textul sursa 
SET SERVEROUTPUT ON;

CREATE OR REPLACE PROCEDURE get_procedure_source(
    schema_name IN VARCHAR2, 
    procedure_name IN VARCHAR2
) AS
    CURSOR c_source IS
        SELECT text
        FROM all_source
        WHERE owner = UPPER(schema_name)  -- Ensure case-insensitivity
        AND name = UPPER(procedure_name)  -- Ensure case-insensitivity
        AND type = 'PROCEDURE'
        ORDER BY line;
BEGIN
    FOR r IN c_source LOOP
        DBMS_OUTPUT.PUT_LINE(r.text);
    END LOOP;
END get_procedure_source;
/

-- afisare
BEGIN
    get_procedure_source('GDIRBD0027', 'SELECT_FILTERED_BILETE');
END;
/