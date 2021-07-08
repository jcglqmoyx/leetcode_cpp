SELECT extra AS 'report_reason', COUNT(DISTINCT (post_id)) AS 'report_count'
FROM Actions
WHERE extra IS NOT NULL
  AND action = 'report'
  AND action_date = '2019-07-04'
GROUP BY extra
;