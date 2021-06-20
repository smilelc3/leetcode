create database if not exists leetcode;
use leetcode;
drop table if exists Person;
drop table if exists Address;
Create table Person
(
    PersonId  int,
    FirstName varchar(255),
    LastName  varchar(255)
);
Create table Address
(
    AddressId int,
    PersonId  int,
    City      varchar(255),
    State     varchar(255)
);
Truncate table Person;
insert into Person (PersonId, LastName, FirstName)
values ('1', 'Wang', 'Allen');
Truncate table Address;
insert into Address (AddressId, PersonId, City, State)
values ('1', '2', 'New York City', 'New York');

# 显示以下信息 FirstName, LastName, City, State，无论地址是否存在
select FirstName, LastName, City, State
from Person
left join Address on Person.PersonId = Address.PersonId;