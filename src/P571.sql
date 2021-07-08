SELECT avg(number) median
FROM (SELECT number,
             SUM(frequency) over(ORDER BY number) asc_accumu, SUM(frequency) over(ORDER BY number desc) desc_accumu
      FROM numbers) t1,
     (SELECT SUM(frequency) total FROM numbers) t2
WHERE asc_accumu >= total / 2
  AND desc_accumu >= total / 2