def is_vowel(letter):
    is_vowel_flag = False
    
    if letter == 'a' or letter == 'e' or letter == 'i' or letter == 'o' or letter == 'u':
        is_vowel_flag = True
    
    return is_vowel_flag

def rule_one_applicable(text):
    rule_one_applicable = False
    
    if is_vowel(text[0]):
        rule_one_applicable = True
    elif text[:2] == 'xr' or text[:2] == 'yt':
        rule_one_applicable = True

def rule_two_applicable(text):
    return not is_vowel(text[0])

def translate(text):

    if rule_one_applicable(text):
        pig_latin_text = text + 'ay'

    elif rule_two_applicable(text):
        while
         
    pass
