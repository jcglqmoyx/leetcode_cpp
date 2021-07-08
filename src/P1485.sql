SELECT sell_date AS 'sell_date', COUNT(DISTINCT product) AS 'num_sold', GROUP_CONCAT(DISTINCT product
        ORDER BY product ASC
        SEPARATOR ',') #用 ','分隔
        AS 'products'    #组内拼接
FROM Activities
GROUP BY sell_date
ORDER BY sell_date;
;