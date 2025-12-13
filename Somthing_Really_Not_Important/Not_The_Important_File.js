define(function(require, exports, module) {
    function e() {
        this.resize(),
        this.bError = !1,
        this.oLanLogin = null,
        this.szDefaultUser = "admin",
        this.iMaxQANum = WebSDK.oSecurityCap.iMaxQANum || 3
    }
    require("config/ui.config"),
    require("ui.tooltips"),
    require("ui.core"),
    require("ui.widget"),
    require("ui.tabs"),
    require("ui.slider"),
    require("ui.jquery"),
    require("QRcode");
    var t = require("common")
      , i = require("webSession")
      , a = require("translator")
      , o = require("dialog")
      , n = require("utils")
      , r = require("encryption")
      , s = require("isapi/response")
      , l = require("common/plugin")
      , u = require("wizard")
      , c = null
      , d = null
      , p = require("isapi/webAuth")
      , m = null;
    e.prototype = {
        resize: function() {},
        init: function() {
            "true" === i.getItem("disPatchLogin") && (window.location.href = "../dispatch/close.asp?" + seajs.web_version),
            $.ajaxSetup({
                statusCode: {
                    401: function() {}
                }
            });
            var e = this
              , n = a.getLanguage("Login")
              , r = a.getLanguage("Wizard");
            return e.oLanLogin = a.appendLanguage([n, t.m_oLanCommon, r]),
            document.title = a.getValue("login"),
            document.cookie || navigator.cookieEnabled ? (e.initController(),
            e.initPlugin(),
            $("#username").focus(),
            e.getDeviceActiveStat(),
            e.getPwdResetCap(),
            void 0) : (e.bError = !0,
            o.alert(a.getValue("cookieError"), null, function() {
                e.bError = !1
            }),
            void 0)
        },
        initController: function() {
            var e = this
              , i = document.createElement("input");
            i.type = "text";
            var r = i.placeholder !== void 0;
            angular.module("loginApp", ["ui.config", "ui.jquery"]).controller("loginController", function($scope, $document, $compile, $q, $timeout) {
                c = $scope,
                $scope.oLan = e.oLanLogin,
                $scope.oLan = a.appendLanguage($scope.oLan, a.getLanguage("Common")),
                $scope.oLan = a.appendLanguage($scope.oLan, a.getLanguage("Config")),
                $scope.szErrorTip = "",
                $scope.username = "",
                $scope.password = "",
                $scope.activeUsername = e.szDefaultUser,
                $scope.oActivePwd = {},
                $scope.bSupportLocalService = !1,
                $scope.bNeedAction = !1,
                $scope.szLanguage = $.cookie("language"),
                $scope.oCap = {
                    bSptQAReset: !1,
                    bSptQACfg: !1,
                    bSupportWithSecurityEmail: !1,
                    bSptGuidExport: !1,
                    aSupportQuestion: [],
                    bSupportActive: !1,
                    iSecurityVersion: 1,
                    bSupportWithHCApp: !1,
                    bMastSetSecurity: !1,
                    bHasQuestion: !1,
                    bHasEmail: !1,
                    bHasEzviz: !1,
                    szTip: a.getValue("QATip1"),
                    bPasswordResetConfigured: !0,
                    bHasGuid: !1
                },
                $scope.oParams = {
                    aQAList: [],
                    bShowSQCfg: !1,
                    szPwd: "",
                    reservedMailbox: "",
                    bShowEmailConfig: !1
                },
                $scope.oWifi = {
                    bSupportWifiEnhance: !1,
                    bSupportWifiRegion: !1,
                    aAreaCountryList: [],
                    bWifiEnhance: !0,
                    szWifiRegion: "default"
                },
                $scope.oParamsEzviz = {
                    bRedirect: !1,
                    szServerIpAddr: "",
                    szRegStatus: "",
                    szVerifyCode: "",
                    szVerifyCodeTip: "",
                    szDeclarationURL: "",
                    szPrivacyPolicyURL: "",
                    oDlgInfo: {
                        szPassword: "",
                        szPasswordConfirm: ""
                    },
                    bEnabledEZVIZTiming: !1,
                    bOldEnabledEZVIZTiming: !1,
                    szTimeMode: "NTP",
                    oTimeXml: null,
                    bStreamEncrypteEnabled: !0
                },
                $scope.oldVerifyCodeRule = function(e) {
                    return {
                        bValid: /^[A-Z]{6,6}$/.test(e),
                        szError: " "
                    }
                }
                ,
                $scope.verifyCodeRule = function(e) {
                    return e ? /^ABCDEF$/.test(e) ? {
                        bValid: !/^ABCDEF$/.test(e),
                        szError: a.getValue("cannotUserABCDEF")
                    } : /^[A-Za-z0-9]{6,12}$/.test(e) ? {
                        bValid: !0,
                        szError: ""
                    } : {
                        bValid: /^[A-Za-z0-9]{6,12}$/.test(e),
                        szError: $scope.oLan.verifyCodeStrengthTip
                    } : {
                        bValid: !1,
                        szError: $scope.oLan.nullTips
                    }
                }
                ,
                $scope.confirmVerifyCode = function() {
                    return {
                        bValid: $scope.oParamsEzviz.oDlgInfo.szPassword === $scope.oParamsEzviz.oDlgInfo.szPasswordConfirm && $scope.oParamsEzviz.oDlgInfo.szPasswordConfirm,
                        szError: $scope.oLan.passNotMatch || ""
                    }
                }
                ,
                $scope.oUtils = n,
                $scope.oInputValid = {},
                $scope.aInputValidList = [],
                $scope.oInputValidUtils = {};
                var i = 12
                  , r = 6
                  , u = {
                    value: "verifyCodeRule"
                };
                $scope.oParamsValid = {
                    oAnswerValid: {
                        oEmpty: {
                            value: !1,
                            error: c.oLan.nullTips
                        },
                        oMaxLength: {
                            value: 128,
                            error: a.getValue("noMoreLength", [128])
                        },
                        bSkipValid: !1,
                        bAttach: !0
                    },
                    oPassword: {
                        oType: {
                            value: "password"
                        },
                        oEmpty: {
                            value: !1,
                            error: a.getValue("nullTips")
                        },
                        oMinLength: {
                            value: 8,
                            error: a.getValue("noLessLength", [8])
                        },
                        oMaxLength: {
                            value: 16,
                            error: a.getValue("noMoreLength", [16])
                        },
                        oChinese: {
                            value: !1,
                            error: a.getValue("notZhChar")
                        },
                        aRegex: [{
                            value: "^(?![0-9]+$)(?![a-z]+$)(?![A-Z]+$)[0-9A-Za-z!#$%&'()*+,-./;<=>?@\\[\\]^_`{|}~\\s*]{1,}$",
                            error: a.getValue("riskyInputPwd")
                        }],
                        bSkipValid: !1
                    },
                    oEmailValid: {
                        oType: {
                            value: "email",
                            error: a.getValue("emailFormatError")
                        },
                        oMinLength: {
                            value: 1,
                            error: a.getValue("noLessLength", [1])
                        },
                        oMaxLength: {
                            value: 32,
                            error: a.getValue("noMoreLength", [32])
                        },
                        oEmpty: {
                            value: !1,
                            error: c.oLan.nullTips
                        },
                        bSkipValid: !1,
                        bAttach: !0
                    },
                    oServerIpAddr: {
                        oMaxLength: {
                            value: 32,
                            error: a.getValue("noMoreLength", [32])
                        },
                        oEmpty: {
                            value: !1,
                            error: c.oLan.nullTips
                        },
                        oChinese: {
                            value: !1,
                            error: c.oLan.notZhChar
                        },
                        bSkipValid: !0,
                        bAttach: !0
                    },
                    oVerifyCode: {
                        oMinLength: {
                            value: r,
                            error: a.getValue("noLessLength", [r])
                        },
                        oMaxLength: {
                            value: i,
                            error: a.getValue("noMoreLength", [i])
                        },
                        oType: u,
                        bSkipValid: !1,
                        oEmpty: {
                            value: !1,
                            error: c.oLan.nullTips
                        },
                        bAttach: !0
                    },
                    oVerifyDlgCode: {
                        oMinLength: {
                            value: r,
                            error: a.getValue("noLessLength", [r])
                        },
                        oMaxLength: {
                            value: i,
                            error: a.getValue("noMoreLength", [i])
                        },
                        oType: u,
                        bSkipValid: !0,
                        bAttach: !0
                    },
                    oVerifyDlgCodeEx: {
                        oType: {
                            value: "confirmVerifyCode"
                        },
                        oMinLength: {
                            value: r,
                            error: a.getValue("noLessLength", [r])
                        },
                        oMaxLength: {
                            value: i,
                            error: a.getValue("noMoreLength", [i])
                        },
                        bSkipValid: !0,
                        bAttach: !0
                    }
                },
                $scope.bPluginInstalled = !1,
                $scope.showLanguageList = function(e) {
                    e.stopPropagation(),
                    $("#language_list").toggle()
                }
                ,
                $scope.changeLanguage = function(t) {
                    e.changeLanguage(t.target.id)
                }
                ,
                $scope.login = function(t) {
                    "anonymous" == t && (this.username = "anonymous",
                    this.password = "******"),
                    $scope.szErrorTip = "",
                    e.doLogin(this, $compile)
                }
                ,
                $scope.docPress = function(t) {
                    13 != t.which || e.bError || e.doLogin(this, $compile)
                }
                ,
                $scope.forgetPwd = function() {
                    window.location.href = "pwdReset.asp"
                }
                ,
                $document.on("click", function() {
                    $("#language_list").hide()
                }),
                $scope.opentGuidDialog = function() {
                    t.exportGuid(c.password, l, s).then(function() {
                        c.oCap.bHasGuid = !0,
                        c.changeQAItem()
                    }, function() {})
                }
                ,
                $scope.changeQuestion = function(e) {
                    var t = window.event;
                    if ("change" === t.type && t.target) {
                        var i = $scope.oParams.aQAList[e].szId - 1;
                        t.target.title = $scope.oCap.aSupportQuestion[i].szQuestionDes
                    }
                }
                ,
                $scope.checkValid = function() {
                    var e = !0;
                    return $(c.oParams.aQAList).each(function() {
                        return this.szAnswer.length ? void 0 : (e = !1,
                        !1)
                    }),
                    e
                }
                ,
                $scope.downloadPlugin = function() {
                    l.downloadPlugin(),
                    l.checkPluginExist(!1, function() {
                        $("#main_plugin").show(),
                        e.initPlugin(),
                        $scope.$$phase || $scope.$digest()
                    })
                }
                ,
                e.initQACfg(),
                $scope.showEzvizQrCode = function() {
                    WebSDK.WSDK_GetDeviceConfig(t.m_szHostName, "getEZVIZQRCode", null, {
                        success: function(e, t) {
                            var i, a = t.EZVIZQRCode.QRCode;
                            i = '<div id="EzvizQrCode">',
                            i += '<canvas id="testCanvas" style="display: none;"></canvas>',
                            i += '<div style="height:256px;" id="output"></div></div>',
                            o.html({
                                szTitle: $scope.oLan.EzvizQrCode,
                                szContent: i,
                                nWidth: 300,
                                nHeight: 400,
                                id: "EzvizQrCode",
                                zIndex: 2e3,
                                oButtons: {
                                    bOK: !1,
                                    bCancel: !1,
                                    bClose: !0
                                }
                            }),
                            $compile(angular.element("#EzvizQrCode"))($scope),
                            setTimeout(function() {
                                $("#testCanvas").get(0) && $("#testCanvas").get(0).getContext ? $("#output").qrcode({
                                    render: "canvas",
                                    width: 256,
                                    height: 256,
                                    text: a
                                }) : $("#output").qrcode({
                                    render: "table",
                                    width: 256,
                                    height: 256,
                                    text: a
                                })
                            })
                        },
                        error: function() {
                            o.tip(a.getValue("networkAbnormal"))
                        }
                    })
                }
                ,
                $scope.saveEmail = function() {
                    return c.oParamsValid.oAnswerValid.bSkipValid = !0,
                    c.oParamsValid.oEmailValid.bSkipValid = !1,
                    c.oParamsValid.oPassword.bSkipValid = !0,
                    c.oParamsValid.oServerIpAddr.bSkipValid = !0,
                    c.oParamsValid.oVerifyCode.bSkipValid = !0,
                    c.oParamsValid.oVerifyDlgCode.bSkipValid = !0,
                    c.oParamsValid.oVerifyDlgCodeEx.bSkipValid = !0,
                    c.oParamsValid.oEmailValid.bSkipValid = !WebSDK.oSecurityCap.bSupportSecurityEmailConfig || c.oParams.reservedMailbox === c.oParams.szDefaultEmailAddr,
                    c.oParamsValid.oEmailValid.bSkipValid ? void 0 : (c.$apply(),
                    c.oInputValidUtils.manualInputValid(),
                    c.oInputValid.bInputValid ? c.oParams.bShowEmailConfig && "" !== c.oParams.reservedMailbox && "" !== c.oParams.reservedMailbox ? t.setSecurityEmail(c.oParams.reservedMailbox, c.password, s, function() {
                        $scope.oCap.bHasEmail = !0,
                        o.tip(a.getValue("saveSucceeded")),
                        $scope.changeQAItem()
                    }, !1) : void 0 : !1)
                }
                ,
                $scope.ReservedMailboxClicked = function() {
                    c.oParams.reservedMailbox === $scope.oParams.szDefaultEmailAddr && (c.oParams.reservedMailbox = "")
                }
                ,
                $scope.ReservedMailboxBlur = function() {
                    $timeout(function() {
                        "" === c.oParams.reservedMailbox && (c.oParams.reservedMailbox = $scope.oParams.szDefaultEmailAddr)
                    })
                }
                ,
                $scope.skipValidVerifyDlgCode = function(e) {
                    c.oParamsValid.oVerifyDlgCode.bSkipValid = e,
                    c.oParamsValid.oVerifyDlgCodeEx.bSkipValid = e
                }
                ,
                $scope.enablePlatform = function() {
                    var e = c.oEzvizCap.bSptVerificationCode && c.oEzvizCap.bSptVerificationLink && c.oEzvizCap.bSptModifyJudge && $scope.oParams.bEnablePlatform;
                    e && ($scope.oInputValidUtils.manualHideTip(["inVerifyCode", "inVerifyCodeEx"]),
                    $scope.oParamsEzviz.oDlgInfo.szPassword = $scope.oParamsEzviz.oDlgInfo.szPasswordConfirm = "",
                    c.skipValidVerifyDlgCode(!1),
                    $.get("advancedPlatformVerificationCode.asp", function(e) {
                        o.html({
                            szTitle: a.getValue("tip"),
                            szContent: e,
                            nWidth: 520,
                            szLeft: "25%",
                            id: "advancedPlatformVerificationCode",
                            zIndex: 2002,
                            oButtons: {
                                bOK: !0,
                                bCancel: !0,
                                bClose: !1
                            },
                            cbOk: function() {
                                return c.oEzvizCap.bVerifyCodeModified ? !0 : ($scope.oInputValidUtils.manualInputValid(["inVerifyCode", "inVerifyCodeEx"], "id"),
                                $scope.checkVerifyCodeValid() ? ($scope.oParamsEzviz.szVerifyCode = $scope.oParamsEzviz.oDlgInfo.szPassword,
                                $scope.$$phase || $scope.$digest(),
                                c.skipValidVerifyDlgCode(!0),
                                void 0) : !1)
                            },
                            cbCancel: function() {
                                $scope.oInputValidUtils.clearInputValidList(),
                                $scope.oParams.bEnablePlatform = !1,
                                $scope.$$phase || $scope.$digest(),
                                c.skipValidVerifyDlgCode(!0)
                            }
                        }),
                        $compile(angular.element("#verifyCodeDlg"))(c),
                        c.$$phase || c.$digest(),
                        $("#verifyCodeDlg").hide().show(),
                        c.initVerifyCodeProvisionLink()
                    }))
                }
                ,
                $scope.initVerifyCodeProvisionLink = function() {
                    var e = m.m_oDeviceCapa.oVerifyCodeInfo;
                    if (e) {
                        c.oParamsEzviz.szDeclarationURL = e.szDeclarationURL,
                        c.oParamsEzviz.szPrivacyPolicyURL = e.szPrivacyPolicyURL;
                        var t = a.getValue("verifyCodeProvisionTip")
                          , i = a.getValue("serviceProvision")
                          , o = t.split(i)
                          , n = a.getValue("privacyPolicy")
                          , r = o[1].split(n)
                          , s = "";
                        s += "<label>" + o[0] + "</label>",
                        s += '<a href="' + (c.oParamsEzviz.szDeclarationURL || "#") + '" target="_blank">' + i + "</a>",
                        s += "<label>" + r[0] + "</label>",
                        s += '<a href="' + (c.oParamsEzviz.szPrivacyPolicyURL || "#") + '" target="_blank">' + n + "</a>",
                        s += "<label>" + r[1] + "</label>",
                        $("#provisionTip").removeAttr("ng-bind").append(s)
                    }
                }
                ,
                $scope.checkVerifyCodeValid = function() {
                    var e = $scope.oParamsEzviz.oDlgInfo.szPassword
                      , t = /^[A-Za-z0-9]{6,12}$/.test(e);
                    if (!t)
                        return !1;
                    var i = $scope.oParamsEzviz.oDlgInfo.szPasswordConfirm;
                    return e !== i ? !1 : !0
                }
                ,
                $scope.saveEzviz = function() {
                    if (c.oParamsValid.oAnswerValid.bSkipValid = !0,
                    c.oParamsValid.oEmailValid.bSkipValid = !0,
                    c.oParamsValid.oPassword.bSkipValid = !0,
                    c.oEzvizCap || c.oEzvizCap.bSptVerificationCode ? (c.oParamsValid.oServerIpAddr.bSkipValid = !1,
                    c.oParamsValid.oVerifyCode.bSkipValid = !1,
                    c.oParamsValid.oVerifyDlgCode.bSkipValid = !1,
                    c.oParamsValid.oVerifyDlgCodeEx.bSkipValid = !1) : (c.oParamsValid.oServerIpAddr.bSkipValid = !0,
                    c.oParamsValid.oVerifyCode.bSkipValid = !0,
                    c.oParamsValid.oVerifyDlgCode.bSkipValid = !0,
                    c.oParamsValid.oVerifyDlgCodeEx.bSkipValid = !0),
                    c.$apply(),
                    c.oInputValidUtils.manualInputValid(),
                    !c.oInputValid.bInputValid)
                        return !1;
                    if (c.oParams.bEnablePlatform && !/^[A-Za-z0-9]{6,12}$/.test(c.oParamsEzviz.szVerifyCode))
                        return $("#verificationCodeOrPassword").blur(),
                        void 0;
                    szUrlType = "ezviz";
                    var e = "<EZVIZ><enabled>" + ("" + c.oParams.bEnablePlatform) + "</enabled>" + "<registerStatus>" + c.oParamsEzviz.szRegStatus + "</registerStatus>" + "<redirect>" + ("" + !c.oParamsEzviz.bRedirect) + "</redirect><serverAddress>"
                      , t = n.checkAddressingType(c.oParamsEzviz.szServerIpAddr);
                    if (e += "<addressingFormatType>" + t.toLowerCase() + "</addressingFormatType>",
                    e += "hostName" == t ? "<hostName>" + c.oParamsEzviz.szServerIpAddr.replace(/</g, "&lt;") + "</hostName>" : "ipv6Address" == t ? "<ipv6Address>" + c.oParamsEzviz.szServerIpAddr + "</ipv6Address>" : "<ipAddress>" + c.oParamsEzviz.szServerIpAddr.replace(/</g, "&lt;") + "</ipAddress>",
                    e += "</serverAddress>",
                    c.oEzvizCap.bSptVerificationCode && (e += "<verificationCode>" + c.oParamsEzviz.szVerifyCode + "</verificationCode>"),
                    c.oEzvizCap.bSupportEZVIZTiming && (e += "<enabledTiming>" + ("" + (c.oParamsEzviz.bEnabledEZVIZTiming && c.oParams.bEnablePlatform)) + "</enabledTiming>"),
                    c.oParams.bSptStreamEncrypte && (e += "<streamEncrypteEnabled>" + c.oParamsEzviz.bStreamEncrypteEnabled + "</streamEncrypteEnabled>"),
                    e += "</EZVIZ>",
                    xmlDoc = n.parseXmlFromStr(e),
                    $(xmlDoc).find("enabled").eq(0).text("" + c.oParams.bEnablePlatform),
                    c.oEzvizCap.bSupportEZVIZTiming) {
                        var i = "";
                        if (c.oParamsEzviz.bEnabledEZVIZTiming !== c.oParamsEzviz.bOldEnabledEZVIZTiming) {
                            if (c.oParamsEzviz.bEnabledEZVIZTiming) {
                                if ("NTP" === c.oParamsEzviz.szTimeMode)
                                    return o.confirm(a.getValue("changeNTPTimingConfirm"), null, function() {
                                        i = "platform",
                                        c.setTimeInfo(i).then(function() {
                                            c.submitData(szUrlType, xmlDoc)
                                        })
                                    }, function() {}),
                                    void 0;
                                i = "platform"
                            } else
                                i = "manual";
                            c.setTimeInfo(i).then(function() {
                                c.submitData(szUrlType, xmlDoc)
                            })
                        } else
                            c.submitData(szUrlType, xmlDoc)
                    } else
                        c.submitData(szUrlType, xmlDoc)
                }
                ,
                $scope.submitData = function(i, a) {
                    WebSDK.WSDK_SetDeviceConfig(t.m_szHostName, i, null, {
                        processData: !1,
                        data: a,
                        success: function(i, a) {
                            var o = $(a).find("statusCode").eq(0).text();
                            "7" === o && s.toRestart(),
                            c.oCap.bHasEzviz = c.oParams.bEnablePlatform,
                            setTimeout(function() {
                                e.getEzvizInfo(),
                                m.m_oDeviceCapa.oVerifyCodeInfo && (WebSDK.WSDK_GetDeviceConfig(t.m_szHostName, "networkCap", null, {
                                    async: !1,
                                    success: function(e, t) {
                                        c.oEzvizCap.bVerifyCodeModified = m.m_oDeviceCapa.oVerifyCodeInfo.bModified = n.nodeValue(t, "verificationCodeModify", "b")
                                    },
                                    error: function() {
                                        c.oEzvizCap.bVerifyCodeModified = m.m_oDeviceCapa.oVerifyCodeInfo.bModified = !0
                                    }
                                }),
                                c.$$phase || c.$digest())
                            }, 10)
                        },
                        error: function(e, t, i) {
                            s.saveState(i)
                        }
                    })
                }
                ,
                $scope.setTimeInfo = function(e) {
                    var i = $q.defer();
                    if (c.oParamsEzviz.oTimeXml) {
                        var a = c.oParamsEzviz.oTimeXml;
                        $(a).find("timeMode").text(e),
                        $(a).find("platformType").text("EZVIZ"),
                        WebSDK.WSDK_SetDeviceConfig(t.m_szHostName, "timeInfo", null, {
                            data: a,
                            success: function(e, t) {
                                c.oParamsEzviz.szTimeMode = n.nodeValue(t, "timeMode"),
                                $timeout(function() {
                                    i.resolve(!0)
                                })
                            },
                            error: function(e, t, a) {
                                s.saveState(a),
                                $timeout(function() {
                                    i.reject(!0)
                                })
                            }
                        })
                    }
                    return i.promise
                }
                ,
                $scope.saveQA = function() {
                    return c.oParamsValid.oAnswerValid.bSkipValid = !1,
                    c.oParamsValid.oEmailValid.bSkipValid = !0,
                    c.oParamsValid.oPassword.bSkipValid = !0,
                    c.oParamsValid.oServerIpAddr.bSkipValid = !0,
                    c.oParamsValid.oVerifyCode.bSkipValid = !0,
                    c.oParamsValid.oVerifyDlgCode.bSkipValid = !0,
                    c.oParamsValid.oVerifyDlgCodeEx.bSkipValid = !0,
                    c.$apply(),
                    c.oInputValidUtils.manualInputValid(),
                    c.oInputValid.bInputValid ? (t.setSecurityQA(c.oParams.aQAList, c.password, s, function() {
                        c.oCap.bHasQuestion = !0,
                        o.tip(a.getValue("saveSucceeded")),
                        c.changeQAItem()
                    }, !1),
                    void 0) : !1
                }
                ,
                $scope.changeQAItem = function() {
                    var e = 0
                      , t = "";
                    $scope.oCap.bHasQuestion && (t += a.getValue("securityQA"),
                    e++),
                    $scope.oCap.bHasEmail && (t += t ? "、" + a.getValue("email") : a.getValue("email"),
                    e++),
                    $scope.oCap.bHasGuid && (t += t ? "、" + a.getValue("exportGuidFile") : a.getValue("exportGuidFile"),
                    e++),
                    $scope.oCap.szTip = e > 0 ? a.getValue("QATip2", [e]) + t : a.getValue("QATip1"),
                    $scope.$apply()
                }
            }).directive("placeholder", function() {
                return {
                    restrict: "A",
                    scope: !1,
                    require: "ngModel",
                    link: function(e, t, i) {
                        if (!r) {
                            var a = parseInt(t.css("padding-left").replace("px", ""), 10)
                              , o = parseInt(t.css("padding-top").replace("px", ""), 10)
                              , n = parseInt(t.css("border-top-width").replace("px", ""), 10);
                            e.$watch("" + i.ngModel, function(e) {
                                if (!angular.isUndefined(e)) {
                                    var r = t.data("placeholder");
                                    if (r || (r = $("<label class='placeholder'>" + i.placeholder + "</label>"),
                                    r.click(function() {
                                        t.focus()
                                    }),
                                    t.data("placeholder", r)),
                                    "" === e) {
                                        $(t).parent().append(r);
                                        var s = Math.round((t.height() - r.height()) / 2) + n + o;
                                        r.css({
                                            left: t.position().left + a + "px",
                                            top: t.position().top + s + "px"
                                        })
                                    } else
                                        r.remove(),
                                        t.removeData("placeholder")
                                }
                            })
                        }
                    }
                }
            }),
            angular.bootstrap(document.body, ["loginApp"])
        },
        initPlugin: function() {
            window.GetSelectWndInfo = function() {}
            ,
            l.initPlugin("0").then(function() {
                c.bPluginInstalled = l.isInstalled(),
                c.$$phase || c.$apply()
            })
        },
        doLogin: function($scope, $compile) {
            var e = this;
            if (e.checkLogin($scope)) {
                var i = $scope.password;
                "anonymous" === $scope.username && (i = "******"),
                p.init({
                    szHttpProtocol: t.m_szHttpProtocol,
                    szHostName: t.m_szHostName,
                    iHttpPort: t.m_iHttpPort
                }),
                p.login($scope.username, i, e.loginSuccess, e.loginError, e, [$scope, $compile])
            }
        },
        loginSuccess: function(e, $scope, $compile) {
            var i = this
              , r = function() {
                o.closeAll();
                try {
                    1 === l.getVideoMode() ? (l.removePlugin(),
                    l.oPlugin = null,
                    l.initPlugin("0").then(function() {
                        s()
                    })) : s()
                } catch (e) {
                    s()
                }
            }
              , s = function() {
                i.getReservedMailboxCap(),
                c.oCap.bSptQACfg = WebSDK.oSecurityCap.bSptQACfg,
                c.oParams.bShowEmailConfig = WebSDK.oSecurityCap.bSupportSecurityEmailConfig,
                c.bSupportPlugin = l.getVideoMode(),
                c.bSupportLocalService = !((2 === c.bSupportPlugin ? 0 : 1) && (1 === c.bSupportPlugin ? 1 : 0));
                var e = l.isInstalled();
                c.oCap.bSptGuidExport = WebSDK.oSecurityCap.bSptGuidExport,
                i.getSecurityEmail(),
                c.oCap.bMastSetSecurity && (WebSDK.WSDK_Request(t.m_szHostName, t.m_iHttpProtocal, t.m_iHttpPort, {
                    cmd: "PasswordResetType",
                    async: !1,
                    success: function(e, t) {
                        c.oCap.bPasswordResetConfigured = "configured" === t.status || "nonsupport" === t.status
                    },
                    error: function() {
                        c.oCap.bPasswordResetConfigured = !0
                    },
                    complete: function() {
                        c.$digest()
                    }
                }),
                i.getQuestionList());
                var n = c.oCap.bSptQACfg || c.oCap.bShowEmailConfig || c.oCap.bSptGuidExport;
                if (n && (c.bNeedAction || c.oCap.bMastSetSecurity && !c.oCap.bPasswordResetConfigured)) {
                    document.onkeydown = function(e) {
                        var t = window.event || e
                          , i = t.keyCode || t.which;
                        return 116 == i ? (t.keyCode ? t.keyCode = 0 : t.which = 0,
                        !1) : void 0
                    }
                    ,
                    m = require("isapi/device"),
                    m.getDeviceCapa(),
                    m.getNetworkCap();
                    var r = $.cookie("language");
                    if (c.oEzvizCap = {
                        bSupportEzviz: m.m_oDeviceCapa.bSupportEZVIZ && "zh" !== r && !1,
                        bSupportEZVIZTiming: m.m_oDeviceCapa.bSupportEZVIZTiming,
                        bShowEZVIZTiming: !1,
                        bSupportEzvizServerAddr: !1,
                        bSupportEzvizRedirect: !1,
                        bSupportStreamAdditionalInfo: !1,
                        bSptVerificationCode: m.m_oDeviceCapa.bSptVerificationCode,
                        bSptVerificationLink: m.m_oDeviceCapa.bSptVerificationLink,
                        aVerificationCodeLen: [6, 12],
                        bVerifyCodeModified: m.m_oDeviceCapa.oVerifyCodeInfo && m.m_oDeviceCapa.oVerifyCodeInfo.bModified,
                        bSptModifyJudge: m.m_oDeviceCapa.oVerifyCodeInfo && m.m_oDeviceCapa.oVerifyCodeInfo.bSptModifyJudge,
                        bOldVerificationCode: m.m_oDeviceCapa.bOldVerificationCode,
                        bSupportEhomeKey: !1,
                        bSupportEZVIZQRCode: !1
                    },
                    i.getEZVIZCap(),
                    i.getEzvizInfo(),
                    c.oEzvizCap.bSptVerificationCode || (c.oParamsValid.oVerifyCode.bSkipValid = !0,
                    c.oParamsValid.oVerifyDlgCode.bSkipValid = !0,
                    c.oParamsValid.oVerifyDlgCodeEx.bSkipValid = !0),
                    "object" == typeof m.m_oDeviceCapa.oVerifyCodeInfo) {
                        var s = m.m_oDeviceCapa.oVerifyCodeInfo;
                        s.bEmpty ? s.bModified || (c.oParamsEzviz.szVerifyCodeTip = a.getValue("modifyDefaultCodeTip")) : c.oParamsEzviz.szVerifyCodeTip = a.getValue("createDefaultCodeTip")
                    }
                    c.oParams.bShowSQCfg = !1,
                    c.oInputValidUtils.clearInputValidList(),
                    $("body").unbind("keydown keypress"),
                    $.get("securityQA.asp", function(t) {
                        e && p.setAuthInfo(c.username, c.password),
                        o.html({
                            szTitle: a.getValue("resetTypeSettings"),
                            szContent: t,
                            nWidth: 650,
                            cbOk: function() {
                                return $scope.oCap.bHasQuestion || $scope.oCap.bHasEmail || $scope.oCap.bHasGuid || "zh" === $scope.szLanguage ? g() : o.alert(a.getValue("QATip1")),
                                !1
                            },
                            oButtons: {
                                bOK: !0,
                                bCancel: !1,
                                bClose: !1
                            }
                        }),
                        $compile(angular.element("#qaDialog2"))(c),
                        c.$digest(),
                        $("#qaDialog2").hide().show(),
                        o.resize(),
                        d = $("#qaDialog2 #tabsQA").tabs({
                            active: 0,
                            remember: !1
                        })
                    })
                } else
                    g()
            }
              , g = function() {
                WebSDK.WSDK_GetDeviceConfig(t.m_szHostName, "sHttpCapa", null, {
                    async: !1,
                    success: function(e, t) {
                        n.nodeValue(t, "GuideCap isSupGuide", "b") ? (l.isInstalled() || f(),
                        l.getLocalConfig().then(function(e) {
                            1 === e.showWizard ? u.confirm(f) : f()
                        })) : f()
                    },
                    error: function() {
                        f()
                    }
                })
            }
              , f = function() {
                var e = decodeURI(document.URL)
                  , i = n.getURIParam("page", e)
                  , a = i;
                if ("" !== i) {
                    var o = i.match(/\[&?(.*?)\]/)
                      , r = ""
                      , s = ["preview.asp", "playback.asp", "download.asp", "config.asp", "mixedTarget.asp"];
                    null !== o && (r = o[1],
                    a = i.replace(o[0], "")),
                    -1 === a.indexOf(".asp") && (a = a.concat(".asp")),
                    "paramconfig.asp" === a && (a = "config.asp"),
                    -1 === $.inArray(a, s) ? a = "preview.asp" : "" !== r && (a += "?" + r)
                } else
                    WebSDK.WSDK_GetDeviceConfig(t.m_szHostName, "clusterCap", null, {
                        async: !1,
                        success: function(e, t) {
                            a = n.nodeValue(t, "isSupportPreview", "t") ? "config.asp" : "preview.asp"
                        },
                        error: function() {
                            a = "preview.asp"
                        }
                    });
                window.location.href = a
            }
              , h = function() {
                return $scope.activeUsername = $scope.username,
                $scope.szPwdErrorTip = "",
                o.html("", $("#active").get(0), 300, null, function() {
                    return $scope.oActivePwd.szPassword = $scope.oActivePwd.szPassword.replace(/\s/g, ""),
                    $scope.oActivePwd.szPasswordConfirm = $scope.oActivePwd.szPasswordConfirm.replace(/\s/g, ""),
                    $scope.oActivePwd.szPassword !== $scope.oActivePwd.szPasswordConfirm || "" === $scope.oActivePwd.szPassword ? ("" === $scope.oActivePwd.szPassword ? $scope.szPwdErrorTip = a.getValue("password") + a.getValue("nullTips") : $scope.oActivePwd.szPassword !== $scope.oActivePwd.szPasswordConfirm ? $scope.szPwdErrorTip = a.getValue("passNotMatch") : "" !== $scope.oActivePwd.szPassword && $scope.activeUsername.length >= 3 && -1 !== $scope.oActivePwd.szPassword.indexOf($scope.activeUsername) && ($scope.szPwdErrorTip = a.getValue("pwdIncludeUser")),
                    o.alert($scope.szPwdErrorTip),
                    !1) : n.checkPasswordComplexity(c.oActivePwd.szPassword, c.activeUsername) ? (WebSDK.WSDK_GetDeviceConfig(t.m_szHostName, "user", null, {
                        success: function(e, i) {
                            $(i).find("User").each(function() {
                                if ($(this).find("userName").eq(0).text() === $scope.username) {
                                    var e = n.createXml();
                                    e.appendChild(e.createProcessingInstruction("xml", "version='1.0' encoding='utf-8'"));
                                    var i = e.createElement("password");
                                    return i.appendChild(e.createTextNode($scope.oActivePwd.szPassword)),
                                    $(this).get(0).appendChild(i),
                                    e.appendChild(this),
                                    WebSDK.WSDK_SetDeviceConfig(t.m_szHostName, "userModify", {
                                        user: $(this).find("id").eq(0).text()
                                    }, {
                                        data: e,
                                        success: function() {
                                            $scope.password = $scope.oActivePwd.szPassword,
                                            r()
                                        },
                                        error: function() {
                                            r()
                                        }
                                    }),
                                    !1
                                }
                            })
                        },
                        error: function() {
                            r()
                        }
                    }),
                    void 0) : !1
                }, function() {
                    r()
                }),
                $("#active").find("input").eq(0).focus(),
                $compile(angular.element("#active"))($scope),
                $scope.$$phase || $scope.$apply(),
                $("#active").hide().show(),
                !1
            };
            e.oExtraInfo.bActivated ? e.oExtraInfo.bRiskPsw ? o.confirm(a.getValue("riskPwdTips"), 300, function() {
                return h()
            }, function() {
                r()
            }) : r() : i.showActiveDialog()
        },
        getQuestionList: function() {
            WebSDK.WSDK_Request(t.m_szHostName, t.m_iHttpProtocal, t.m_iHttpPort, {
                cmd: "questionInfoList",
                type: "GET",
                async: !1,
                success: function(e, t) {
                    $(t).find("Question").each(function() {
                        n.nodeValue(this, "mark", "b") && (c.oCap.bHasQuestion = !0)
                    })
                }
            })
        },
        getEZVIZCap: function() {
            WebSDK.WSDK_GetDeviceConfig(t.m_szHostName, "getEZVIZCap", null, {
                async: !1,
                success: function(e, t) {
                    c.oEzvizCap.bSupportEZVIZQRCode = n.nodeValue($(t), "isSupportEZVIZQRCode", "b")
                }
            })
        },
        getEzvizInfo: function() {
            WebSDK.WSDK_GetDeviceConfig(t.m_szHostName, "ezviz", null, {
                async: !1,
                success: function(e, i) {
                    if (c.oEzvizCap.bShowEZVIZTiming = n.nodeValue($(i), "enabled", "b"),
                    c.oParamsEzviz.szRegStatus = n.nodeValue($(i), "registerStatus"),
                    c.oParamsEzviz.szBindStatus = n.nodeValue($(i), "bindStatus"),
                    c.oParamsEzviz.bEnabledEZVIZTiming = n.nodeValue($(i), "enabledTiming", "b"),
                    c.oParamsEzviz.bOldEnabledEZVIZTiming = n.nodeValue($(i), "enabledTiming", "b"),
                    c.oParams.bEnablePlatform = n.nodeValue($(i), "enabled", "b"),
                    c.oCap.bHasEzviz = c.oParams.bEnablePlatform,
                    c.changeQAItem(),
                    $(i).find("streamEncrypteEnabled").length > 0 && (c.oParamsEzviz.bStreamEncrypteEnabled = n.nodeValue($(i), "streamEncrypteEnabled", "b"),
                    c.oParams.bSptStreamEncrypte = !0),
                    $(i).find("serverAddress").length > 0) {
                        c.oEzvizCap.bSupportEzvizServerAddr = !0;
                        var a = n.nodeValue($(i), "addressingFormatType");
                        c.oParamsEzviz.szServerIpAddr = "hostname" == a ? n.nodeValue($(i), "hostName") : $(i).find("ipAddress").length > 0 ? n.nodeValue($(i), "ipAddress") : n.nodeValue($(i), "ipv6Address")
                    }
                    $(i).find("redirect").length > 0 && (c.oEzvizCap.bSupportEzvizRedirect = !0,
                    c.oParamsEzviz.bRedirect = !n.nodeValue($(i), "redirect", "b")),
                    $(i).find("verificationCode").length && (c.oParamsEzviz.szVerifyCode = n.nodeValue(i, "verificationCode")),
                    WebSDK.WSDK_GetDeviceConfig(t.m_szHostName, "timeInfo", null, {
                        success: function(e, t) {
                            c.oParamsEzviz.oTimeXml = t,
                            c.oParamsEzviz.szTimeMode = n.nodeValue(t, "timeMode")
                        }
                    })
                }
            })
        },
        getTimeInfo: function() {
            WebSDK.WSDK_GetDeviceConfig(t.m_szHostName, "timeInfo", null, {
                success: function(e, t) {
                    c.oParamsEzviz.oTimeXml = t,
                    c.oParamsEzviz.szTimeMode = n.nodeValue(t, "timeMode")
                }
            })
        },
        loginError: function(e, $scope) {
            var t = this;
            t.bError = !0;
            var i = e.subStatusCode
              , n = e.status;
            if ("maxSessionUserLink" === i) {
                var r = "<div style='padding: 10px;'>" + a.getValue("maxUserLink") + "</div>";
                return o.alert(r, null, function() {
                    t.bError = !1,
                    $("#username").focus(),
                    $("#password").blur(),
                    $scope.username = "",
                    $scope.password = "",
                    $scope.szErrorTip = "",
                    $scope.$apply()
                }),
                void 0
            }
            if (504 == n)
                o.alert(a.getValue("connectTimeout"), null, function() {
                    t.bError = !1
                });
            else if (401 === n) {
                if (e.lockStatus) {
                    var s = e.unlockTime
                      , l = "";
                    60 > s ? l = a.getValue("seconds") : (s = Math.ceil(s / 60),
                    l = a.getValue("minute"));
                    var r = "<div style='padding: 10px;'>" + a.getValue("userLock", [s, l]) + "</div>";
                    return o.alert(r, null, function() {
                        t.bError = !1,
                        $("#username").focus(),
                        $("#password").blur(),
                        $scope.username = "",
                        $scope.password = "",
                        $scope.szErrorTip = "",
                        $scope.$apply()
                    }),
                    void 0
                }
                var u = e.retryLoginTime;
                $("#username").focus(),
                $("#password").blur(),
                $scope.szErrorTip = "" === u ? a.getValue("loginError") : a.getValue("loginLockError", [u]),
                t.bError = !1,
                $scope.username = "",
                $scope.password = "",
                $scope.$apply()
            } else
                o.alert(a.getValue("networkError"), null, function() {
                    t.bError = !1
                })
        },
        checkLogin: function($scope) {
            return 0 == n.lengthw($scope.username) ? ($scope.szErrorTip = a.getValue("inputUsername"),
            $("#username").focus(),
            !1) : 0 == n.lengthw($scope.password) ? ($scope.szErrorTip = a.getValue("inputPassword"),
            $("#password").focus(),
            !1) : n.isChinese($scope.username) ? ($("#username").focus(),
            $scope.szErrorTip = a.getValue("notSupportZhUser"),
            $scope.username = "",
            $scope.$apply(),
            !1) : !0
        },
        changeLanguage: function(e) {
            $.cookie("language", e),
            location.href = location.href
        },
        getDeviceActiveStat: function() {
            var e = this;
            WebSDK.WSDK_Request(t.m_szHostName, t.m_iHttpProtocal, t.m_iHttpPort, {
                cmd: "activateStatus",
                success: function(t, i) {
                    "true" != n.nodeValue(i, "Activated") && (c.bNeedAction = !0,
                    e.showActiveDialog())
                }
            })
        },
        showActiveDialog: function() {
            var e = this;
            $("body").unbind("keydown keypress").bind("keydown", function(t) {
                13 === t.keyCode && (e.doActive(),
                c.$apply())
            }),
            o.html({
                szTitle: a.getValue("activeDevice"),
                szContent: $("#active").get(0),
                nWidth: 540,
                cbOk: function() {
                    return e.doActive(),
                    c.$apply(),
                    !1
                },
                oButtons: {
                    bOK: !0
                }
            }),
            $("#active").find("input").eq(0).focus()
        },
        doActive: function() {
            var e = this;
            return "" !== c.oActivePwd.szPassword && c.activeUsername.length >= 3 && -1 !== c.oActivePwd.szPassword.indexOf(c.activeUsername) ? (o.alert(a.getValue("pwdIncludeUser")),
            void 0) : c.oActivePwd.szPassword !== c.oActivePwd.szPasswordConfirm ? (o.alert(a.getValue("passNotMatch")),
            void 0) : (n.checkPasswordComplexity(c.oActivePwd.szPassword, c.activeUsername) && r.encrypt(c.oActivePwd.szPassword, n.getRSABits(), !1, function(t) {
                e.activeDevice(t)
            }),
            void 0)
        },
        activeDevice: function(e) {
            var i = this
              , a = n.parseXmlFromStr("<?xml version='1.0' encoding='UTF-8'?><ActivateInfo><password>" + e + "</password></ActivateInfo>");
            WebSDK.WSDK_Request(t.m_szHostName, t.m_iHttpProtocal, t.m_iHttpPort, {
                cmd: "activate",
                type: "PUT",
                processData: !1,
                data: a,
                success: function() {
                    o.closeAll(),
                    c.username = c.activeUsername,
                    c.password = c.oActivePwd.szPassword,
                    c.oParams.bShowSQCfg = !0,
                    p.init({
                        szHttpProtocol: t.m_szHttpProtocol,
                        szHostName: t.m_szHostName,
                        iHttpPort: t.m_iHttpPort
                    }),
                    p.login(c.username, c.password, i.activeLoginSuccess, i.activeLoginError, i, [c])
                },
                error: function(e, t, i) {
                    s.saveState(i)
                }
            })
        },
        activeLoginSuccess: function() {
            var e = this;
            c.oCap.bSupportActive = WebSDK.oSecurityCap.bSupportIPCActivatePassword,
            e.getWifiCap(),
            c.oWifi.bSupportWifiEnhance || c.oWifi.bSupportWifiRegion || c.oCap.bSupportActive ? (c.$$phase || c.$digest(),
            o.html({
                szTitle: a.getValue("basicConfig"),
                szContent: $("#wifiConfig").get(0),
                nWidth: 300,
                cbOk: function() {
                    return (c.oWifi.bSupportWifiEnhance || c.oWifi.bSupportWifiRegion) && c.oCap.bSupportActive ? e.setActivePwd() && e.setWifiInfo() : c.oCap.bSupportActive ? e.setActivePwd() : (e.setWifiInfo(),
                    void 0)
                },
                oButtons: {
                    bOK: !0
                }
            }),
            $("#ipcActivePassword").focus()) : c.login()
        },
        activeLoginError: function() {
            c.login()
        },
        initQACfg: function() {
            var e = this;
            c.oCap.aSupportQuestion.length = 0;
            for (var t in c.oLan.questionList) {
                var i = t.substr(6);
                c.oCap.aSupportQuestion.push({
                    szId: Number(i),
                    szQuestionDes: c.oLan.questionList[t]
                })
            }
            for (var a = 0; e.iMaxQANum > a; a++)
                c.oParams.aQAList[a] = {
                    szId: a + 1,
                    szAnswer: ""
                }
        },
        getSecurityEmail: function() {
            WebSDK.oSecurityCap.bSupportSecurityEmailConfig && WebSDK.WSDK_GetDeviceConfig(t.m_szHostName, "SecurityEmail", null, {
                async: !1,
                dataType: "JSON",
                success: function(e, t) {
                    t.SecurityEmail && (c.oParams.reservedMailbox = t.SecurityEmail.SecurityInformation[0].emailAddress),
                    t.SecurityEmail && (c.oParams.szDefaultEmailAddr = t.SecurityEmail.SecurityInformation[0].emailAddress),
                    "" != c.oParams.szDefaultEmailAddr && (c.oCap.bHasEmail = !0,
                    c.changeQAItem())
                }
            })
        },
        getPwdResetCap: function() {
            WebSDK.WSDK_Request(t.m_szHostName, t.m_iHttpProtocal, t.m_iHttpPort, {
                cmd: "securityExtCap",
                async: !1,
                success: function(e, t) {
                    c.oCap.bSptGuidImport = n.nodeValue(t, "isSupportWithGUIDFileData", "b"),
                    c.oCap.bSptQAReset = n.nodeValue(t, "isSupportWithSecurityQuestion", "b"),
                    c.oCap.bSupportWithSecurityEmail = n.nodeValue(t, "isSupportWithSecurityEmail", "b"),
                    c.oCap.bSupportWithHCApp = n.nodeValue(t, "isSupportWithHCApp", "b"),
                    c.oCap.bMastSetSecurity = n.nodeValue(t, "minResetAdminPassWordNum", "i") >= 1
                },
                error: function() {
                    c.oCap.bSptGuidImport = !1,
                    c.oCap.bSptQAReset = !1,
                    c.oCap.bSupportWithHCApp = !1,
                    c.oCap.bMastSetSecurity = !1
                },
                complete: function() {
                    c.$digest()
                }
            })
        },
        getReservedMailboxCap: function() {
            WebSDK.WSDK_GetDeviceConfig(t.m_szHostName, "SecurityEmailCap", null, {
                async: !1,
                dataType: "JSON",
                success: function(e, t) {
                    t.SecurityEmailCap && (c.oParamsValid.oEmailValid.oMinLength.value = t.SecurityEmailCap.emailAddress["@min"],
                    c.oParamsValid.oEmailValid.oMinLength.error = a.getValue("noLessLength", [t.SecurityEmailCap.emailAddress["@min"]]),
                    c.oParamsValid.oEmailValid.oMaxLength.value = t.SecurityEmailCap.emailAddress["@max"],
                    c.oParamsValid.oEmailValid.oMaxLength.error = a.getValue("noLessLength", [t.SecurityEmailCap.emailAddress["@max"]]))
                }
            })
        },
        getWifiCap: function() {
            var e = this;
            WebSDK.WSDK_GetDeviceConfig(t.m_szHostName, "wlanRegionCap", null, {
                async: !1,
                success: function(t, i) {
                    n.nodeValue(i, "supportWifiEnhancement", "b") && (c.oWifi.bSupportWifiEnhance = !0),
                    n.nodeValue(i, "supportRegion", "b") && (c.oWifi.bSupportWifiRegion = !0,
                    $(i).find("WifiManualChannel").each(function() {
                        var e = $(this).eq(0).find("region").eq(0).text()
                          , t = "default" === e ? c.oLan.defaultCountry : c.oLan[e];
                        c.oWifi.aAreaCountryList.push({
                            value: e,
                            name: t
                        })
                    }),
                    e.getWifiInfo()),
                    c.$apply()
                }
            })
        },
        getWifiInfo: function() {
            WebSDK.WSDK_GetDeviceConfig(t.m_szHostName, "wlanRegionInfo", null, {
                async: !1,
                success: function(e, t) {
                    c.oWifi.szWifiRegion = $(t).find("region").eq(0).text(),
                    c.$apply()
                }
            })
        },
        setWifiInfo: function() {
            var e = "<?xml version='1.0' encoding='utf-8'?><Region>";
            c.oWifi.bSupportWifiEnhance && (e += "<wifiEnhancementEnabled>" + c.oWifi.bWifiEnhance + "</wifiEnhancementEnabled>"),
            c.oWifi.bSupportWifiRegion && (e += "<region>" + c.oWifi.szWifiRegion + "</region>"),
            e += "</Region>",
            e = n.parseXmlFromStr(e),
            WebSDK.WSDK_SetDeviceConfig(t.m_szHostName, "wlanRegionInfo", null, {
                async: !1,
                data: e,
                complete: function(e, t, i) {
                    s.saveState(i),
                    c.login()
                }
            })
        },
        setActivePwd: function() {
            var e = this
              , i = c.oParams.szPwd;
            if (n.isEmpty(i) || n.isChinese(i) || 8 > n.lengthw(i) || n.lengthw(i) > 16)
                return !1;
            if (i.indexOf("admin") > -1)
                return o.tip(a.getValue("pwdCannotIncludeAdmin")),
                !1;
            if (!/^(?![0-9]+$)(?![a-z]+$)(?![A-Z]+$)[0-9A-Za-z!#$%&'()*+,-./;<=>?@\\[\]^_`{|}~\s*]{1,}$/.test(i))
                return o.alert(a.getValue("riskyInputPwd")),
                !1;
            var r = "<?xml version='1.0' encoding='UTF-8'?><IPCActivatePasswd>";
            r += "<password>" + i + "</password>",
            r += "</IPCActivatePasswd>";
            var s = n.parseXmlFromStr(r);
            WebSDK.WSDK_SetDeviceConfig(t.m_szHostName, "IPCActivatePwd", null, {
                async: !1,
                data: s,
                complete: function() {
                    c.oWifi.bSupportWifiEnhance || c.oWifi.bSupportWifiRegion ? e.setWifiInfo() : c.login()
                }
            })
        }
    },
    module.exports = new e
});
