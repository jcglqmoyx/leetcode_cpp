SELECT question_id AS survey_log
FROM survey_log
GROUP BY question_id
ORDER BY sum(if(ACTION = 'answer', 1, 0)) / SUM(if(ACTION = 'show', 1, 0)) DESC limit 1