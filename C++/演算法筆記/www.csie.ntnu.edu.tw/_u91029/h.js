h = {};

// create menu, banners add '\n'
h.Menu = function()
{
	var menu = document.createElement('DIV');
	menu.className = 'm';
	menu.innerHTML += '<div class="li"><a href="index.html">◀ Index</a></div>';

	var childs = document.querySelectorAll('div.a>div.h>p.b');
	for(let i = 0; i < childs.length; i++)
	{
		var banner = childs[i];
		banner.innerHTML = banner.innerHTML.replace(/: /gi,':<br>').replace(/（/gi,'<br>（');
		menu.innerHTML += '<div class="li"><a href="#' + (i+1) + '">' + banner.innerHTML + '</a></div>';
		banner.parentNode.parentNode.id = (i+1);
	}
	document.body.appendChild(menu);

	window.addEventListener('scroll', function(){menu.style.left = -window.pageXOffset;});
}

// reset the style of English words in <p>
h.English = function()
{
	for(let p of document.querySelectorAll('p'))
	{
		for(let node of p.childNodes)
			if (node.nodeType == 3)
				node.nodeValue = node.nodeValue.replace(/([ -ωᴀ-Ɀ]+)/gi, ' $1 ');
			else
				node.innerHTML = node.innerHTML.replace(/([ -ωᴀ-Ɀ]+)/gi, ' $1 ');

		p.innerHTML = p.innerHTML.replace(/^ /, '').replace(/ $/, '');
	}
}

// generate the hyperlinks of the exercises
h.ProbLink = function()
{
	var ojs = 'uva icpc timus pku cf sphere'.split(' ');
	var oj = 'uva';
	for(let p of document.querySelectorAll('p.e'))
		for(let s of p.textContent.split(' '))
		{
			var name = s.toLowerCase();
			if(ojs.indexOf(name) != -1) {oj = name; continue;}

			var t = s;
			if     (oj == 'uva')    t = '<a href="http://uva.onlinejudge.org/external/' + s.slice(0,-2) + '/' + s + '.html">' + s + '</a>';
			else if(oj == 'icpc')   t = '<a href="http://icpcarchive.ecs.baylor.edu/external/' + s.slice(0,-2) + '/' + s + '.pdf">' + s + '</a>';
			else if(oj == 'timus')  t = '<a href="http://acm.timus.ru/problem.aspx?space=' + s.slice(0,-3) + '&num=' + s + '">' + s + '</a>';
			else if(oj == 'pku')    t = '<a href="http://poj.org/problem?id=' + s + '">' + s + '</a>';
			else if(oj == 'cf')     t = '<a href="http://codeforces.com/problemset/problem/' + s.slice(0,-1) + '/' + s.slice(-1) + '">' + s + '</a>';
			else if(oj == 'sphere') t = '<a href="http://www.spoj.com/problems/' + s + '/">' + s + '</a>';

			p.innerHTML = p.innerHTML.replace(s, t);
		}
}

// load video on scrolling
h.LazyLoad = function()
{
	var zz = document.querySelectorAll('.z');
	if (zz.length == 0) return;

	load();
	window.addEventListener('resize', load);
	window.addEventListener('scroll', load);

	function visible(element)
	{
		var rect = element.getBoundingClientRect();
		return !(rect.top >= window.innerHeight || rect.bottom <= 0
			|| rect.left >= window.innerWidth || rect.right <= 0);
	}

	function load()
	{
		for(let z of zz) if(visible(z))
		{
			var div = document.createElement('DIV');
			div.innerHTML = z.childNodes[0].nodeValue;
			z.parentNode.replaceChild(div, z);
		}
	}
};

// regular expressions
h.types =
	'char bool short int long float double unsigned auto clock_t size_t va_list';

h.keywords =
	'break case catch class const const_cast continue '
	+'default delete do dynamic_cast else enum explicit extern '
	+'if for friend goto inline mutable namespace new operator '
	+'private public protected register reinterpret_cast return '
	+'sizeof static static_cast struct switch template this '
	+'throw true false try typedef typeid typename union '
	+'using virtual void volatile while';

h.MakeRegExp = function(str) 
{
	return '\\b' + str.replace(/ /g, '\\b|\\b') + '\\b';
}

h.regexps =
[
	{r:/\/\*[\s\S]*?\*\//gm, css:'comments'},
	{r:/\/\/.*$/gm, css:'comment'},
	{r:/^ *#.*/gm, css:'macro'},
	{r:/"([^"\\\n]|\\.)*"/g, css:'string'},
	{r:/'([^'\\\n]|\\.)*'/g, css:'char'},
	{r:new RegExp(h.MakeRegExp(h.keywords),'g'), css:'keyword'},
	{r:new RegExp(h.MakeRegExp(h.types),'g'), css:'type'},
	{r:/[^\W\d]\w*/g, css:'word'},
	{r:/0[xX][\da-fA-F]+/g, css:'hex'},
	{r:/(\d*\.)?\d+([eE]\d+)?/g, css:'value'}
];

// HTML entity
h.HTML2String = function(html)
{
	return html
	.replace(/&amp;/g, '&')
	.replace(/&lt;/g, '<')
	.replace(/&gt;/g, '>')
	.replace(/&quot;/g, '"')
	.replace(/&nbsp;/g, ' ');
}

h.String2HTML = function(str)
{
	return str
	.replace(/&/g, '&amp;')
	.replace(/</g, '&lt;')
	.replace(/>/g, '&gt;')
	.replace(/"/g, '&quot;')
	.replace(/ /g, '&nbsp;');
}

h.Tab = function(text)
{
	var stext = '';
	var lines = h.HTML2String(text).replace(/\n$/g, '').split('\n');
	for(line of lines)
	{
		for(let p = 0; (p = line.indexOf('\t')) != -1;)
			line = line.replace(/\t/, '    '.slice(0, 4-p%4));
		stext += line + '\n';
	}
	return stext;
}

h.Color = function(str, css)
{
	if(str == null || str.length == 0) return;

	var lines = h.String2HTML(str).split('\n');
	for(var i = 0; i < lines.length; i++)
	{
		if(lines[i] != '')
		{
			var span = document.createElement('SPAN');
			if(css != null) span.className = css;
			span.innerHTML = lines[i];
			h.li.appendChild(span);
		}

		if(i + 1 < lines.length)
		{
			// add line break for copy-paste
			if(h.li.innerHTML == '') h.li.innerHTML = '&nbsp;';
			h.ol.appendChild(h.li);
			h.li = document.createElement('LI');
		}
	}
}

h.Parse = function(element)
{
	var text = h.Tab(element.innerHTML);
	var m = [0,0,0,0,0,0,0,0,0,0];
	var q = 0;
	h.ol = document.createElement('OL');
	h.li = document.createElement('LI');

	while(1)
	{
		var ii = -1;
		var p = text.length;
		for(let i = 0; i < h.regexps.length; i++)
		{
			if(m[i] == null) continue;
			if(m[i] == 0 || m[i].index < q)
			{
				var r = h.regexps[i].r;
				r.lastIndex = q;
				m[i] = r.exec(text);
			}
			if(m[i] == null) continue;
			if(m[i].index < p) {p = m[i].index; ii = i;}
		}

		if(ii == -1) {h.Color(text.slice(q), null); break;}
		h.Color(text.slice(q, p), null);
		h.Color(m[ii][0], h.regexps[ii].css);
		q = h.regexps[ii].r.lastIndex;
	}

	var bar = document.createElement('DIV');
	bar.className = 'bar';
	bar.innerHTML = '&nbsp;';
	if(element.attributes['t'] != null)
		bar.innerHTML = element.attributes['t'].value;

	var div = document.createElement('DIV');
	div.className = 'sh';
	div.appendChild(bar);
	div.appendChild(h.ol);

	element.parentNode.replaceChild(div, element);
}

h.Highlight = function()
{
	for(textarea of document.querySelectorAll('textarea'))
		h.Parse(textarea);
}

h.Highlight();
h.Menu();
h.English();
h.ProbLink();
h.LazyLoad();