from lxml import etree
import re
import os
import requests

def getData(url):
	path = 'D:/carsImg' + "/cars/"
	if not os.path.exists(path):
		os.makedirs(path)

	header={
		'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.74 Safari/537.36 Edg/99.0.1150.46'
	}

	result= requests.get(url,headers=header)
	result.encoding = 'utf-8'
	html2=etree.HTML(result.text) #初始化生成一个XPath解析对象

'''抓取车辆信息'''
	pattern = r'\<p\>(.*)\</p\>'
	dataSrc = re.findall(pattern, result.text)
	with open('D:/carsImg/cars.txt', "a") as f1:
		for carData in dataSrc:
			f1.write(carData + "\n")

'''抓取图片'''
	imgSrc = html2.xpath('/html/body/div[3]/ul[3]/li/a/img/@src')
	for img in imgSrc:
		imgName = img.split("/")[-1]
		temp = requests.get(img, headers = header).content
		with open(path +imgName, 'wb') as f2:
			f2.write(temp)

if __name__=='__main__':
	for i in range(1,3):
		url='https://car.autohome.com.cn/jingxuan/list-11-p{}.html'.format(i)
		getData(url)
