(window.webpackJsonp=window.webpackJsonp||[]).push([[33],{mwzk:function(e,t,r){"use strict";r.r(t),function(e){var n=r("q1tI"),a=r.n(n),i=r("0cfB"),o=r("/MKj"),c=r("3SGO"),l=r("t8hP"),u=r("kDLi"),s=r("Y8YH"),m=r("ZGyg"),p=r("HJRA"),d=r("ZFWI");function f(e,t){var r=Object.keys(e);if(Object.getOwnPropertySymbols){var n=Object.getOwnPropertySymbols(e);t&&(n=n.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),r.push.apply(r,n)}return r}function b(e){for(var t=1;t<arguments.length;t++){var r=null!=arguments[t]?arguments[t]:{};t%2?f(Object(r),!0).forEach((function(t){v(e,t,r[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(r)):f(Object(r)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(r,t))}))}return e}function v(e,t,r){return t in e?Object.defineProperty(e,t,{value:r,enumerable:!0,configurable:!0,writable:!0}):e[t]=r,e}function g(e,t,r,n,a,i,o){try{var c=e[i](o),l=c.value}catch(e){return void r(e)}c.done?t(l):Promise.resolve(l).then(n,a)}function w(e){return function(){var t=this,r=arguments;return new Promise((function(n,a){var i=e.apply(t,r);function o(e){g(i,n,a,o,c,"next",e)}function c(e){g(i,n,a,o,c,"throw",e)}o(void 0)}))}}function h(e,t){return function(e){if(Array.isArray(e))return e}(e)||function(e,t){if(!(Symbol.iterator in Object(e)||"[object Arguments]"===Object.prototype.toString.call(e)))return;var r=[],n=!0,a=!1,i=void 0;try{for(var o,c=e[Symbol.iterator]();!(n=(o=c.next()).done)&&(r.push(o.value),!t||r.length!==t);n=!0);}catch(e){a=!0,i=e}finally{try{n||null==c.return||c.return()}finally{if(a)throw i}}return r}(e,t)||function(){throw new TypeError("Invalid attempt to destructure non-iterable instance")}()}var y={main:{icon:"grafana",text:"Invite",subTitle:"Register your Grafana account",breadcrumbs:[{title:"Login",url:"login"}]},node:{text:""}},O={updateLocation:c.d};t.default=Object(i.hot)(e)(Object(o.connect)((function(e){return{code:e.location.routeParams.code}}),O)((function(e){var t=e.code,r=h(Object(n.useState)(),2),i=r[0],o=r[1],c=h(Object(n.useState)(),2),f=c[0],v=c[1],g=h(Object(n.useState)(),2),O=g[0],j=g[1];Object(s.a)(w(regeneratorRuntime.mark((function e(){var r;return regeneratorRuntime.wrap((function(e){for(;;)switch(e.prev=e.next){case 0:return e.next=2,Object(l.getBackendSrv)().get("/api/user/invite/"+t);case 2:r=e.sent,o({email:r.email,name:r.name,username:r.email}),v(r.name||r.email||r.username),j(r.invitedBy);case 6:case"end":return e.stop()}}),e)}))),[]);var E=function(){var e=w(regeneratorRuntime.mark((function e(r){return regeneratorRuntime.wrap((function(e){for(;;)switch(e.prev=e.next){case 0:return e.next=2,Object(l.getBackendSrv)().post("/api/user/invite/complete",b({},r,{inviteCode:t}));case 2:window.location.href=Object(d.c)().appSubUrl+"/";case 3:case"end":return e.stop()}}),e)})));return function(t){return e.apply(this,arguments)}}();return a.a.createElement(m.a,{navModel:y},a.a.createElement(m.a.Contents,null,a.a.createElement("h3",{className:"page-sub-heading"},"Hello ",f||"there","."),a.a.createElement("div",{className:"modal-tagline p-b-2"},a.a.createElement("em",null,O||"Someone")," has invited you to join Grafana and the organization"," ",a.a.createElement("span",{className:"highlight-word"},p.b.user.orgName),a.a.createElement("br",null),"Please complete the following and choose a password to accept your invitation and continue:"),a.a.createElement(u.Form,{defaultValues:i,onSubmit:E},(function(e){var t=e.register,r=e.errors;return a.a.createElement(a.a.Fragment,null,a.a.createElement(u.Field,{invalid:!!r.email,error:r.email&&r.email.message,label:"Email"},a.a.createElement(u.Input,{placeholder:"email@example.com",name:"email",ref:t({required:"Email is required",pattern:{value:/^\S+@\S+$/,message:"Email is invalid"}})})),a.a.createElement(u.Field,{invalid:!!r.name,error:r.name&&r.name.message,label:"Name"},a.a.createElement(u.Input,{placeholder:"Name (optional)",name:"name",ref:t})),a.a.createElement(u.Field,{invalid:!!r.username,error:r.username&&r.username.message,label:"Username"},a.a.createElement(u.Input,{placeholder:"Username",name:"username",ref:t({required:"Username is required"})})),a.a.createElement(u.Field,{invalid:!!r.password,error:r.password&&r.password.message,label:"Password"},a.a.createElement(u.Input,{type:"password",placeholder:"Password",name:"password",ref:t({required:"Password is required"})})),a.a.createElement(u.Button,{type:"submit"},"Sign Up"))}))))})))}.call(this,r("3UD+")(e))}}]);
//# sourceMappingURL=SignupInvited.ddf7518003180e1ca7bc.js.map