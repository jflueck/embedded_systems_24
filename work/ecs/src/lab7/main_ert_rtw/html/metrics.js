function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["main_M_"] = {file: "C:\\Users\\ecs\\Desktop\\embedded_systems_24\\work\\ecs\\src\\lab7\\main_ert_rtw\\main.c",
	size: 8};
	 this.metricsArray.var["main_U"] = {file: "C:\\Users\\ecs\\Desktop\\embedded_systems_24\\work\\ecs\\src\\lab7\\main_ert_rtw\\main.c",
	size: 4};
	 this.metricsArray.var["main_Y"] = {file: "C:\\Users\\ecs\\Desktop\\embedded_systems_24\\work\\ecs\\src\\lab7\\main_ert_rtw\\main.c",
	size: 4};
	 this.metricsArray.fcn["main_initialize"] = {file: "C:\\Users\\ecs\\Desktop\\embedded_systems_24\\work\\ecs\\src\\lab7\\main_ert_rtw\\main.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["main_step"] = {file: "C:\\Users\\ecs\\Desktop\\embedded_systems_24\\work\\ecs\\src\\lab7\\main_ert_rtw\\main.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["main_terminate"] = {file: "C:\\Users\\ecs\\Desktop\\embedded_systems_24\\work\\ecs\\src\\lab7\\main_ert_rtw\\main.c",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="main_metrics.html">Global Memory: 16(bytes) Maximum Stack: 0(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
