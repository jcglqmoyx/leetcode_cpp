SELECT ids AS id,
       cnt AS num
FROM (SELECT ids,
             COUNT(*) AS cnt
      FROM (SELECT requester_id AS ids
            FROM request_accepted
            UNION ALL
            SELECT accepter_id
            FROM request_accepted) AS tbl1
      GROUP BY ids) AS tbl2
ORDER BY cnt DESC limit 1;