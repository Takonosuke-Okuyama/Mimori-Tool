kansuList = ['', '', '二', '三', '四', '五', '六', '七', '八', '九']
hiraganaList = [ \
	'あ', 'い', 'う', 'え', 'お', \
	'か', 'き', 'く', 'け', 'こ', \
	'さ', 'し', 'す', 'せ', 'そ', \
	'た', 'ち', 'つ', 'て', 'と', \
	'な', 'に', 'ぬ', 'ね', 'の', \
	'は', 'ひ', 'ふ', 'へ', 'ほ', \
	'ま', 'み', 'む', 'め', 'も', \
	'や', 'ゆ', 'よ', \
	'ら', 'り', 'る', 'れ', 'ろ', \
	'わ', 'を', 'ん']

def makeKansu(arg_num):
    if(arg_num == 0):
        return '零'

    thousand, mod = divmod(arg_num, 1000)
    hundred, mod = divmod(mod, 100)
    ten, one = divmod(mod, 10)

    kansu = ''
    if thousand:
        kansu += f'{kansuList[thousand]}千'
    if hundred:
        kansu += f'{kansuList[hundred]}百'
    if ten:
        kansu += f'{kansuList[ten]}十'
    if(one == 1):
    	kansu += '一'
    else:
    	kansu += kansuList[one]

    return kansu


def makeMori(arg_num):
	num_mori , mod = divmod(arg_num, 3)
	num_hayashi, num_ki = divmod(mod, 2)

	if(num_ki and num_mori):
		num_mori -= 1
		num_hayashi += 2
		num_ki -= 1

	mori = ''
	mori += '森' * num_mori
	mori += '林' * num_hayashi
	mori += '木' * num_ki

	return mori


def makeSuzuko(arg_num):
	num = (arg_num % 46) + 9
	suzuko = f'{hiraganaList[num] * 2}\u3099こ'

	return suzuko


def makeMimoriSuzuko(arg_num):
	mimoriSuzuko = ''
	mimoriSuzuko += makeKansu(arg_num)
	mimoriSuzuko += makeMori(arg_num)
	mimoriSuzuko += makeSuzuko(arg_num)
	return mimoriSuzuko


if __name__ == '__main__':
    num = input('何森?: ')
    if num.isdecimal():
        mimori = makeMimoriSuzuko(int(num))
        print(mimori)
    else:
    	print('ダメです')
