--CREATE DATABASE DENEME

--USE DENEME

DROP TABLE IF EXISTS TREATMENT;
DROP TABLE IF EXISTS MEDICINE;
DROP TABLE IF EXISTS PRESCRIPTION;
DROP TABLE IF EXISTS PATIENT;
DROP TABLE IF EXISTS NURSE;
DROP TABLE IF EXISTS DOCTOR;
DROP TABLE IF EXISTS HOSPITAL;


CREATE TABLE DOCTOR(

	ID INT NOT NULL PRIMARY KEY,

	Doctor_name VARCHAR(15),

	Doctor_surname VARCHAR(15),

	Doctor_department VARCHAR(20)
)


CREATE TABLE NURSE(

ID INT NOT NULL PRIMARY KEY,

Nurse_name VARCHAR(15),

Nurse_surname VARCHAR(15),

Nurse_department VARCHAR(20)
)


CREATE TABLE PATIENT(

ID INT NOT NULL PRIMARY KEY,

Patient_name VARCHAR(15),

Patient_surname VARCHAR(15),

Patient_complaint VARCHAR(20)
)


CREATE TABLE TREATMENT(

Nurse_ID INT NOT NULL,

Doctor_ID INT NOT NULL,

Prescription_ID INT NOT NULL,

PRIMARY KEY (Doctor_ID,Nurse_ID,Prescription_ID),

 FOREIGN KEY (Nurse_ID) REFERENCES NURSE(ID),
  FOREIGN KEY (Doctor_ID) REFERENCES DOCTOR(ID),

	Treatment_medicine VARCHAR(20),
	Treatment_no_medicine VARCHAR(20)
)

CREATE TABLE PRESCRIPTION(

Prescription_ID INT NOT NULL PRIMARY KEY,


Prescription_Patient_name VARCHAR(15),

Prescription_Patient_surname VARCHAR(15),

)


CREATE TABLE HOSPITAL(

Hospital_ID INT NOT NULL PRIMARY KEY,

Hospital_Block_number INT,

Hospital_deparment VARCHAR(50),

Hospital_employees INT


)


CREATE TABLE MEDICINE(

Doctor_ID INT NOT NULL,

Nurse_ID INT NOT NULL,

Medicine_ID INT NOT NULL,

PRIMARY KEY (Doctor_ID,Nurse_ID,Medicine_ID),

 FOREIGN KEY (Nurse_ID) REFERENCES NURSE(ID),
  FOREIGN KEY (Doctor_ID) REFERENCES DOCTOR(ID),


  Medicine_name VARCHAR(20),
  Medicine_time FLOAT,
  Medicine_Side_effect VARCHAR(30)

)

INSERT INTO DOCTOR VALUES(1,'Metin','Akgul','Noroloji')
INSERT INTO DOCTOR VALUES(2,'Yunus','Donmez','Dermatoloji')
INSERT INTO DOCTOR VALUES(3,'Selim','Kara','Psikiyatri')

INSERT INTO NURSE VALUES(4,'Serra','Ozdemir','Klinik')
INSERT INTO NURSE VALUES(5,'Hazal','Kesim','Yenidogan')
INSERT INTO NURSE VALUES(6,'Zeynep','Akgul','YogunBakým')

INSERT INTO PATIENT VALUES(7,'Ahmet','Yavuz','BasAgrisi')
INSERT INTO PATIENT VALUES(8,'Salih','Yavuz','Sivilce')
INSERT INTO PATIENT VALUES(9,'Beyza','Yavuz','Psikolojik')

INSERT INTO TREATMENT VALUES(4,2,7,'BoyunMr','BOS')
INSERT INTO TREATMENT VALUES(5,1,8,'BeyinMr','BOS')
INSERT INTO TREATMENT VALUES(6,3,9,'NULL','Ilacsiz')

INSERT INTO PRESCRIPTION VALUES(20,'Ahmet','Yavuz')
INSERT INTO PRESCRIPTION VALUES(21,'Salih','Yavuz')
INSERT INTO PRESCRIPTION VALUES(22,'Beyza','Yavuz')

INSERT INTO HOSPITAL VALUES(7,3,'Psikiyatri',10)
INSERT INTO HOSPITAL VALUES(8,4,'Noroloji',15)
INSERT INTO HOSPITAL VALUES(9,2,'Psikiyatri',8)

INSERT INTO MEDICINE VALUES(2,5,11,'Parol',20.00,'BasDonmesi')
INSERT INTO MEDICINE VALUES(3,4,12,'B12',13.00,'Sivilcelenme')
INSERT INTO MEDICINE VALUES(1,6,13,'Isotretinoin',15.00,'KasAgrýlarý')



SELECT P.Patient_name, P.Patient_surname

FROM PATIENT P
WHERE P.ID IN (
    SELECT DISTINCT T.Prescription_ID
    FROM TREATMENT T
    JOIN DOCTOR D ON T.Doctor_ID = D.ID
    WHERE D.Doctor_department = 'Noroloji'
);


SELECT M.Medicine_name, M.Medicine_time, M.Medicine_Side_effect, N.Nurse_name, N.Nurse_surname, D.Doctor_name, D.Doctor_surname

FROM MEDICINE M

JOIN NURSE N ON M.Nurse_ID = N.ID
JOIN DOCTOR D ON M.Doctor_ID = D.ID;

SELECT P.Patient_name,P.Patient_surname,D.Doctor_name,D.Doctor_surname,N.Nurse_name, N.Nurse_surname

FROM PATIENT P

JOIN TREATMENT T ON P.ID = T.Prescription_ID
JOIN DOCTOR D ON T.Doctor_ID = D.ID
JOIN NURSE N ON T.Nurse_ID = N.ID;

GO

CREATE PROCEDURE GetNorolojiPatients
AS
BEGIN
    SELECT P.Patient_name, P.Patient_surname
    FROM PATIENT P
    WHERE P.ID IN (
        SELECT DISTINCT T.Prescription_ID
        FROM TREATMENT T
        JOIN DOCTOR D ON T.Doctor_ID = D.ID
        WHERE D.Doctor_department = 'Noroloji'
    );
END
GO


CREATE FUNCTION Get_TotalEmployees()
RETURNS INT
AS
BEGIN
    DECLARE @TotalEmployees INT;
    SELECT @TotalEmployees = SUM(Hospital_employees) FROM HOSPITAL;
    RETURN @TotalEmployees;
END
GO

CREATE TRIGGER Hospital_InsertTrigger
ON HOSPITAL
AFTER INSERT
AS
BEGIN
    INSERT INTO HospitalLog (LogMessage, LogDate)
    VALUES ('New hospital record added', GETDATE());
END
GO
	SELECT dbo.Get_TotalEmployees();
	EXEC GetNorolojiPatients;