SELECT FirstName, LastName, City, State
FROM Person p
         LEFT JOIN Address ag ON p.PersonId = a.PersonId;