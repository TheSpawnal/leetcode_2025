
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


#++
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        """
        Problem analysis:
        - given an array of logs
        - each log starts with an identifier, continued with words
        - 2 types: letter & digit logs. All words after identifier match id type
        - Letter logs need to come before digit logs
        - Letter logs are sorted by content, if contents are the same sort by identifier
        - Digit logs need to stay in the original relative order

        Approach brainstorm:
        - Seperate logs by type
        - Sort letter logs
        - Concatenate letters + digits again
        """

        # Seperate logs
        letter_logs = []
        digit_logs = []
        for log in logs:
            # Split identifier and content
            parts = log.split(' ', 1)
            content = parts[1]

            # Check if letter or digit log
            if content[0].isalpha():
                letter_logs.append(log)
            else:
                digit_logs.append(log)
        
        # Sort letter logs
        def sort_key(log):
            parts = log.split(' ', 1)
            identifier = parts[0]
            content = parts[1]
            return (content, identifier)

        letter_logs.sort(key=sort_key)

        # Concatenate logs
        return letter_logs + digit_logs
        
