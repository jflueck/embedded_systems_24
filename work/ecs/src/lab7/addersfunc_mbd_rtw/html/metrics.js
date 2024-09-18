function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.fcn["AdderFunction_Outputs_wrapper"] = {file: "C:\\Users\\ecs\\Desktop\\embedded_systems_24\\work\\ecs\\src\\lab7\\AdderFunction_wrapper.c",
	stack: 7,
	stackTotal: 7};
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
	 this.codeMetricsSummary = '<a href="addersfunc_metrics.html">Global Memory: 0(bytes) Maximum Stack: 7(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
