DROP DATABASE IF EXISTS успеваемость;
CREATE DATABASE успеваемость;
USE успеваемость;

CREATE TABLE IF NOT EXISTS группы (
  `НомерГруппы` INT UNSIGNED NOT NULL,
  `КоличествоСтудентов` INT UNSIGNED NOT NULL,
  `Куратор` VARCHAR(45) NOT NULL,
  UNIQUE INDEX `nomergr_UNIQUE` (`НомерГруппы` ASC));


CREATE TABLE IF NOT EXISTS студенты (
  `НомерЗачетки` INT UNSIGNED NOT NULL,
  `Группа` INT UNSIGNED NOT NULL,
  `Фамилия` VARCHAR(45) NOT NULL,
  `Имя` VARCHAR(45) NOT NULL,
  `Фото` BLOB NULL DEFAULT NULL,
  PRIMARY KEY (`НомерЗачетки`),
  INDEX `gruppa_idx` (`Группа` ASC) VISIBLE,
  CONSTRAINT `Работник`
    FOREIGN KEY (`Группа`)
    REFERENCES `успеваемость`.`группы` (`НомерГруппы`)
    ON DELETE CASCADE
    ON UPDATE CASCADE);


CREATE TABLE IF NOT EXISTS оценки (
  `idОценки` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `НомерЗачетки` INT UNSIGNED NOT NULL,
  `Предмет` VARCHAR(45) NOT NULL,
  `Оценка` INT UNSIGNED NOT NULL,
  `Дата` DATE NOT NULL,
  PRIMARY KEY (`idОценки`, `НомерЗачетки`),
  INDEX `НомерЗачетки` (`НомерЗачетки` ASC) VISIBLE,
  INDEX `date_index` USING BTREE (`Дата`) VISIBLE,
  CONSTRAINT `fk_оценки_студенты1`
    FOREIGN KEY (`НомерЗачетки`)
    REFERENCES `успеваемость`.`студенты` (`НомерЗачетки`)
    ON DELETE CASCADE
    ON UPDATE CASCADE);



show databases;
show tables from успеваемость;
show columns from группы from успеваемость;
use успеваемость;

insert into группы values ("9", 23, "Иванов");
insert into группы values  ("6",15 , "Петров");
insert into группы values  ("4",20 , "Сидоров");
insert into группы values  ("3",21 , "Аганинов");
insert into группы values  ("2",10 , "Соловьев");
insert into группы values  ("1",10 , "Уханина");

select * from группы;

insert into студенты values (1, "9" ,"Селюков", "Константин" , NULL  ); 
insert into студенты values (2, "9" ,"Антон", "Харитонов" , NULL );
insert into студенты values (3, "9" , "Купалов", "Андрей", NULL  ); 
insert into студенты values (4, "9" ,"Перлова", "Анна" , NULL );
insert into студенты values (5, "6" ,"Седков", "Петр" , NULL  ); 
insert into студенты values (6, "6" ,"Дубов", "Антон", NULL );
insert into студенты values (7, "6" ,"Самсова", "Ирина" , NULL  ); 
insert into студенты values (8, "4" ,"Галов", "Вадим" , NULL );
insert into студенты values (9, "4" ,"Малов", "Никита" , NULL  ); 
insert into студенты values (10, "4" ,"Пилов", "Андрей", NULL );
insert into студенты values (11, "12" ,"Федоров", "Федор" , NULL  ); 
insert into студенты values (12, "12" ,"Петров", "Петр" , NULL );
insert into студенты values (13, "1" ,"Сидоров", "Сидр" , NULL  ); 
insert into студенты values (14, "1" ,"Антонов", "Антон" , NULL );

select * from студенты;


insert into оценки values (1,"1", "мат анал", 5 , '2015-12-5');
insert into оценки values (2,"2", "мат анал", 5 , '2015-12-5');
insert into оценки values (4,"3",  "инфа",4  , '2015-12-5');
insert into оценки values (5,"4",   "мат анал", 4 , '2015-12-5');
insert into оценки values (6,"5",   "мат анал", 3 , '2015-12-5');
insert into оценки values (7,"6",   "инфа", 2 , '2015-12-5');
insert into оценки values (8,"7",   "мат анал", 2 , '2015-12-5');
insert into оценки values (9,"8",   "слово", 4 , '2015-12-5');
insert into оценки values (10,"9",   "слово", 3 , '2015-12-5');
insert into оценки values (11,"10",   "физика", 4 , '2015-12-5');
insert into оценки values (12,"12",   "физика",  2 , '2015-12-5');
insert into оценки values (13,"13",   "физика",  3 , '2015-12-5');
insert into оценки values (14,"1",  "инфа",4  , '2015-12-5');


select * from оценки;

DROP VIEW IF EXISTS v1;
 CREATE VIEW v1 AS SELECT оценки.НомерЗачетки,оценки.Предмет,
 оценки.Оценка FROM оценки WHERE оценки.Оценка>3 WITH CHECK OPTION; ;

 SELECT * FROM v1 ;


DROP FUNCTION IF EXISTS plus;
DELIMITER $$
 
CREATE FUNCTION plus(a int,b int) 
RETURNS int
    DETERMINISTIC
BEGIN
    DECLARE result INT; 
   
 SET result = a+b;
 
 RETURN (result); 
END$$
 
DELIMITER ;
 
Select plus(4,7);



DROP PROCEDURE IF EXISTS count_och;
delimiter $$
CREATE PROCEDURE count_och()
BEGIN
SELECT count(*)
FROM оценки
WHERE `Оценка`> 2 ;
END$$
delimiter ;

CALL count_och();



DROP TRIGGER IF EXISTS del_;
DELIMITER $$
CREATE TRIGGER успеваемость.del_ AFTER DELETE ON группы FOR EACH ROW
BEGIN
DELETE FROM студенты WHERE `Группа` = OLD.НомерГруппы;
END$$
DELIMITER ;



DROP TRIGGER IF EXISTS trig;
DELIMITER $$
CREATE TRIGGER успеваемость.trig BEFORE INSERT ON студенты
FOR EACH ROW
BEGIN
DECLARE some_var INT DEFAULT 0;
SELECT count(*) INTO some_var FROM группы
WHERE NEW.`Группа`= группы.НомерГруппы ;
IF some_var = 0 THEN
SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Ошибка! Введено несуществующее значение';
END IF;
END$$

DELIMITER ;


