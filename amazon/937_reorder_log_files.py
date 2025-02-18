
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        digit_logs=[]
        letter_logs=[]
        for log in logs: 
            log_list = log.split(" ")
            if log_list[1].isnumeric():
                digit_logs.append(log)
            else:
                new_log = [log, log_list[1:], log_list[0]]
                letter_logs.append(new_log)
        letter_logs.sort(key=lambda x:(x[1],x[2]))
        letter_logs = [letter[0] for letter in letter_logs]
        letter_logs.extend(digit_logs)
        return letter_logs