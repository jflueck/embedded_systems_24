function CodeDefine() { 
this.def = new Array();
this.def["MyWallModel_B"] = {file: "MyWallModel_c.html",line:30,type:"var"};
this.def["MyWallModel_DW"] = {file: "MyWallModel_c.html",line:33,type:"var"};
this.def["MyWallModel_M_"] = {file: "MyWallModel_c.html",line:36,type:"var"};
this.def["MyWallModel_M"] = {file: "MyWallModel_c.html",line:37,type:"var"};
this.def["MyWallModel_step"] = {file: "MyWallModel_c.html",line:40,type:"fcn"};
this.def["MyWallModel_initialize"] = {file: "MyWallModel_c.html",line:162,type:"fcn"};
this.def["MyWallModel_terminate"] = {file: "MyWallModel_c.html",line:289,type:"fcn"};
this.def["B_MyWallModel_T"] = {file: "MyWallModel_h.html",line:58,type:"type"};
this.def["DW_MyWallModel_T"] = {file: "MyWallModel_h.html",line:67,type:"type"};
this.def["RT_MODEL_MyWallModel_T"] = {file: "MyWallModel_types_h.html",line:27,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:59,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:73,type:"type"};
this.def["creal32_T"] = {file: "rtwtypes_h.html",line:83,type:"type"};
this.def["creal64_T"] = {file: "rtwtypes_h.html",line:88,type:"type"};
this.def["creal_T"] = {file: "rtwtypes_h.html",line:93,type:"type"};
this.def["cint8_T"] = {file: "rtwtypes_h.html",line:100,type:"type"};
this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:107,type:"type"};
this.def["cint16_T"] = {file: "rtwtypes_h.html",line:114,type:"type"};
this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:121,type:"type"};
this.def["cint32_T"] = {file: "rtwtypes_h.html",line:128,type:"type"};
this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:135,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:153,type:"type"};
this.def["flexTimer_pwm0_FaultConfig"] = {file: "ftm0_pwm_params_c.html",line:4,type:"var"};
this.def["flexTimer_pwm0_IndependentChannelsConfig"] = {file: "ftm0_pwm_params_c.html",line:38,type:"var"};
this.def["flexTimer_pwm0_PwmConfig"] = {file: "ftm0_pwm_params_c.html",line:53,type:"var"};
this.def["flexTimer_pwm0_InitConfig"] = {file: "ftm0_pwm_params_c.html",line:67,type:"var"};
this.def["ftmStateStruct0"] = {file: "ftm0_pwm_params_c.html",line:90,type:"var"};
this.def["flexTimer_pwm3_FaultConfig"] = {file: "ftm3_pwm_params_c.html",line:4,type:"var"};
this.def["flexTimer_pwm3_IndependentChannelsConfig"] = {file: "ftm3_pwm_params_c.html",line:38,type:"var"};
this.def["flexTimer_pwm3_PwmConfig"] = {file: "ftm3_pwm_params_c.html",line:53,type:"var"};
this.def["flexTimer_pwm3_InitConfig"] = {file: "ftm3_pwm_params_c.html",line:67,type:"var"};
this.def["ftmStateStruct3"] = {file: "ftm3_pwm_params_c.html",line:90,type:"var"};
this.def["SYSTEM_INIT_TASK"] = {file: "mbd_main_c.html",line:31,type:"fcn"};
this.def["SYSTEM_TASK"] = {file: "mbd_main_c.html",line:37,type:"fcn"};
this.def["LPIT0_Ch0_IRQHandler"] = {file: "mbd_main_c.html",line:44,type:"fcn"};
this.def["lpit0_init"] = {file: "mbd_main_c.html",line:50,type:"fcn"};
this.def["main"] = {file: "mbd_main_c.html",line:93,type:"fcn"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["MyWallModel_c.html"] = "../MyWallModel.c";
	this.html2Root["MyWallModel_c.html"] = "MyWallModel_c.html";
	this.html2SrcPath["MyWallModel_h.html"] = "../MyWallModel.h";
	this.html2Root["MyWallModel_h.html"] = "MyWallModel_h.html";
	this.html2SrcPath["MyWallModel_private_h.html"] = "../MyWallModel_private.h";
	this.html2Root["MyWallModel_private_h.html"] = "MyWallModel_private_h.html";
	this.html2SrcPath["MyWallModel_types_h.html"] = "../MyWallModel_types.h";
	this.html2Root["MyWallModel_types_h.html"] = "MyWallModel_types_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["ftm0_pwm_params_c.html"] = "../ftm0_pwm_params.c";
	this.html2Root["ftm0_pwm_params_c.html"] = "ftm0_pwm_params_c.html";
	this.html2SrcPath["ftm0_pwm_params_h.html"] = "../ftm0_pwm_params.h";
	this.html2Root["ftm0_pwm_params_h.html"] = "ftm0_pwm_params_h.html";
	this.html2SrcPath["ftm3_pwm_params_c.html"] = "../ftm3_pwm_params.c";
	this.html2Root["ftm3_pwm_params_c.html"] = "ftm3_pwm_params_c.html";
	this.html2SrcPath["ftm3_pwm_params_h.html"] = "../ftm3_pwm_params.h";
	this.html2Root["ftm3_pwm_params_h.html"] = "ftm3_pwm_params_h.html";
	this.html2SrcPath["mbd_main_c.html"] = "../mbd_main.c";
	this.html2Root["mbd_main_c.html"] = "mbd_main_c.html";
	this.html2SrcPath["s32k_clock_init_h.html"] = "../s32k_clock_init.h";
	this.html2Root["s32k_clock_init_h.html"] = "s32k_clock_init_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"MyWallModel_c.html","MyWallModel_h.html","MyWallModel_private_h.html","MyWallModel_types_h.html","rtwtypes_h.html","ftm0_pwm_params_c.html","ftm0_pwm_params_h.html","ftm3_pwm_params_c.html","ftm3_pwm_params_h.html","mbd_main_c.html","s32k_clock_init_h.html"];
