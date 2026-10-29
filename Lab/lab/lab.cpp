#include "out.h"


PIMAGE_TLS_CALLBACK __dyn_tls_init_callback;
undefined __mingw_invalidParameterHandler;
_TCHAR * *envp;
int _newmode;
undefined cpp_unhandled_exception_filter;
int argc;
undefined safe_flush;
_TCHAR * *argv;
_PVFV[1] __xc_z;
int managedapp;
int _commode;
int has_cctor;
void *__native_startup_lock;
_PIFV[1] __xi_a;
_PVFV[1] __xc_a;
int __globallocalestatus;
_PIFV[1] __xi_z;
undefined _matherr;
int _fmode;
__enative_startup_state __native_startup_state;
int _MINGW_INSTALL_DEBUG_MATHERR;
int __mingw_app_type;
int _dowildcard;
undefined __gcc_deregister_frame;
undefined _ZSt3cin;
_f__acrt_iob_func __imp___acrt_iob_func;
undefined _ZSt4cout;
func_ptr *p;
pseudoRelocItemV2[2] pseudoRelocItemV2_ARRAY_140004a1c;
undefined4 __DELAY_IMPORT_DIRECTORY_end__;
undefined __do_global_dtors;
int initialized;
int maxSections;
sSecInfo *the_secs;
IMAGE_DOS_HEADER IMAGE_DOS_HEADER_140000000;
undefined UNK_140001f0a;
undefined4 __RUNTIME_PSEUDO_RELOC_LIST_END__;
int was_init;
fUserMathErr stUserMathErr;
IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER_140000188;
undefined DAT_140000458;
undefined *PTR__fmode_140008238;
undefined *PTR__commode_140008228;
undefined *PTR___initenv_1400081f8;
_invalid_parameter_handler handler;

void __mingw_invalidParameterHandler
               (wchar_t *expression,wchar_t *function,wchar_t *file,uint line,uintptr_t pReserved)

{
  return;
}



LONG cpp_unhandled_exception_filter(EXCEPTION_POINTERS *exception_data)

{
  LONG LVar1;
  
  LVar1 = 0;
  if ((exception_data->ExceptionRecord->ExceptionCode & 0x20ffffff) == 0x20474343) {
    LVar1 = (exception_data->ExceptionRecord->ExceptionFlags & 1) - 1;
  }
  return LVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void safe_flush(void)

{
  fflush((FILE *)0x0);
  return;
}



EXCEPTION_DISPOSITION
__mingw_SEH_signal_dispatcher
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          void *DispatcherContext)

{
  int iVar1;
  _EXCEPTION_POINTERS local_18;
  
                    // Unresolved local var: long action@[???]
  if ((ExceptionRecord->ExceptionFlags & 2) == 0) {
    local_18.ExceptionRecord = (PEXCEPTION_RECORD)ExceptionRecord;
    local_18.ContextRecord = (PCONTEXT)ContextRecord;
    iVar1 = _XcptFilter(ExceptionRecord->ExceptionCode,&local_18);
    if (iVar1 == -1) {
      return ExceptionContinueExecution;
    }
    if (iVar1 != 0) {
                    // WARNING: Subroutine does not return
      _exit(ExceptionRecord->ExceptionCode);
    }
  }
  return ExceptionContinueSearch;
}



// WARNING: Removing unreachable block (ram,0x000140001415)
// WARNING: Removing unreachable block (ram,0x00014000141f)
// WARNING: Unknown calling convention -- yet parameter storage is locked

int __tmainCRTStartup(void)

{
  void *pvVar1;
  _TCHAR **pp_Var2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int extraout_EAX;
  void *pvVar6;
  char ***pppcVar7;
  FILE *_File;
  int *piVar8;
  _TCHAR **pp_Var9;
  size_t sVar10;
  _TCHAR *_Dst;
  _TCHAR **pp_Var11;
  ulonglong uVar12;
  ulonglong uVar13;
  longlong unaff_GS_OFFSET;
  bool bVar14;
  _startupinfo startinfo;
  
                    // Unresolved local var: void * lock_free@[???]
                    // Unresolved local var: void * fiberid@[???]
                    // Unresolved local var: BOOL nested@[???]
                    // Unresolved local var: int ret@[???]
                    // Unresolved local var: ulonglong ret@[???]
  pvVar1 = *(void **)(*(longlong *)(unaff_GS_OFFSET + 0x30) + 8);
  while( true ) {
    pvVar6 = (void *)0x0;
    LOCK();
    bVar14 = __native_startup_lock == (void *)0x0;
    pvVar3 = pvVar1;
    if (!bVar14) {
      pvVar6 = __native_startup_lock;
      pvVar3 = __native_startup_lock;
    }
    __native_startup_lock = pvVar3;
    UNLOCK();
    if (bVar14) {
      bVar14 = false;
      goto LAB_1400010ec;
    }
    if (pvVar1 == pvVar6) break;
    Sleep(1000);
  }
  bVar14 = true;
LAB_1400010ec:
  if (__native_startup_state == __initializing) {
    _amsg_exit(0x1f);
    __mingw_app_type = 1;
    iVar4 = __tmainCRTStartup();
    return iVar4;
  }
  if (__native_startup_state == __uninitialized) {
    __native_startup_state = __initializing;
    _File = __acrt_iob_func(2);
    setvbuf((FILE *)_File,(char *)0x0,4,0);
    iVar4 = _crt_atexit(safe_flush);
    if (iVar4 == 0) {
      _pei386_runtime_relocator();
      mingw_set_invalid_parameter_handler(__mingw_invalidParameterHandler);
      _fpreset();
                    // Unresolved local var: PIMAGE_DOS_HEADER pDOSHeader@[???]
                    // Unresolved local var: PIMAGE_NT_HEADERS pPEHeader@[???]
                    // Unresolved local var: PIMAGE_OPTIONAL_HEADER32 pNTHeader32@[???]
                    // Unresolved local var: PIMAGE_OPTIONAL_HEADER64 pNTHeader64@[???]
      managedapp = 0;
      if (__mingw_app_type != 0) goto LAB_140001398;
      __set_app_type(1);
      do {
        piVar8 = __p__fmode();
        *piVar8 = _fmode;
        piVar8 = __p__commode();
        *piVar8 = _commode;
        iVar4 = _setargv();
        if (-1 < iVar4) {
          if (_MINGW_INSTALL_DEBUG_MATHERR == 1) {
            __mingw_setusermatherr(_matherr);
          }
          if (__globallocalestatus == -1) {
            _configthreadlocale(-1);
          }
          iVar4 = _initterm_e(__xi_a,__xi_z);
          if (iVar4 != 0) goto LAB_14000143e;
          startinfo.newmode = _newmode;
          iVar5 = __getmainargs(&argc,&argv,&envp,_dowildcard,&startinfo);
          iVar4 = argc;
          if (-1 < iVar5) {
            uVar12 = (ulonglong)(uint)argc;
                    // Unresolved local var: _TCHAR * * avl@[???]
                    // Unresolved local var: int i@[???]
                    // Unresolved local var: _TCHAR * * n@[???]
            pp_Var9 = malloc((longlong)(argc + 1) << 3);
            pp_Var2 = argv;
            if (pp_Var9 != (_TCHAR **)0x0) {
              pp_Var11 = pp_Var9;
              if (iVar4 < 1) {
LAB_1400013b5:
                *pp_Var11 = (_TCHAR *)0x0;
                argv = pp_Var9;
                SetUnhandledExceptionFilter(cpp_unhandled_exception_filter);
                _initterm(__xc_a,__xc_z);
                __main();
                __native_startup_state = __initialized;
                goto LAB_140001115;
              }
              uVar13 = 1;
              while( true ) {
                sVar10 = strlen(pp_Var2[uVar13 - 1]);
                _Dst = malloc(sVar10 + 1);
                pp_Var9[uVar13 - 1] = _Dst;
                if (_Dst == (_TCHAR *)0x0) break;
                    // Unresolved local var: size_t l@[???]
                memcpy(_Dst,pp_Var2[uVar13 - 1],sVar10 + 1);
                if (uVar12 == uVar13) {
                  pp_Var11 = pp_Var9 + uVar12;
                  goto LAB_1400013b5;
                }
                uVar13 = uVar13 + 1;
              }
            }
          }
        }
        _amsg_exit(8);
LAB_140001398:
        __set_app_type(2);
      } while( true );
    }
    _amsg_exit(0x1a);
LAB_14000143e:
    _amsg_exit(10);
    iVar4 = extraout_EAX;
  }
  else {
    has_cctor = 1;
LAB_140001115:
    if (!bVar14) {
      LOCK();
      __native_startup_lock = (void *)0x0;
      UNLOCK();
    }
    if (__dyn_tls_init_callback != (PIMAGE_TLS_CALLBACK)0x0) {
      (*__dyn_tls_init_callback)((PVOID)0x0,2,(PVOID)0x0);
    }
    pppcVar7 = __p___initenv();
    iVar4 = argc;
    pp_Var2 = envp;
    *pppcVar7 = envp;
    iVar4 = main(iVar4,argv,pp_Var2);
    if (managedapp != 0) {
      if (has_cctor == 0) {
        _cexit();
      }
      return iVar4;
    }
  }
                    // WARNING: Subroutine does not return
  exit(iVar4);
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int WinMainCRTStartup(void)

{
  int iVar1;
  
  __mingw_app_type = 1;
  iVar1 = __tmainCRTStartup();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int mainCRTStartup(void)

{
  int iVar1;
  
  __mingw_app_type = 0;
  iVar1 = __tmainCRTStartup();
  return iVar1;
}



int atexit(_PVFV func)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x000140002280. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = atexit((_func_5014 *)func);
  return iVar1;
}



void __gcc_register_frame(void)

{
  atexit(__gcc_deregister_frame);
  return;
}



void __gcc_deregister_frame(void)

{
  return;
}



int __cdecl main(int _Argc,char **_Argv,char **_Env)

{
  int iVar1;
  FILE *_File;
  ostream *poVar2;
  int iVar3;
  int iVar4;
  undefined1 local_d8 [16];
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined4 local_78;
  string local_68 [32];
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  __main();
  _File = (*__imp___acrt_iob_func)(0);
  freopen("MatrixCPP_INP.txt","r",(FILE *)_File);
  local_1c = 0;
  local_20 = 0;
  local_24 = 0;
  std::__cxx11::string::string(local_68);
  local_d8 = (undefined1  [16])0x0;
  local_c8 = (undefined1  [16])0x0;
  local_b8 = (undefined1  [16])0x0;
  local_a8 = (undefined1  [16])0x0;
  local_98 = (undefined1  [16])0x0;
  local_88 = (undefined1  [16])0x0;
  local_78 = 0;
  local_44 = 5;
  local_48 = 5;
  for (local_2c = 0; local_2c < 5; local_2c = local_2c + 1) {
    for (local_30 = 0; local_30 < 5; local_30 = local_30 + 1) {
      std::istream::operator>>
                ((istream *)&_ZSt3cin,
                 (int *)(local_d8 + ((longlong)local_2c * 5 + (longlong)local_30) * 4));
    }
  }
  for (local_34 = 0; local_34 < 5; local_34 = local_34 + 1) {
    for (local_38 = 0; local_38 < 5; local_38 = local_38 + 1) {
      if (*(int *)(local_d8 + ((longlong)local_34 * 5 + (longlong)local_38) * 4) == 0) {
        local_1c = local_1c + 1;
      }
      else {
        local_24 = (local_1c + 5) / 5;
        poVar2 = std::operator<<((ostream *)&_ZSt4cout,"So 1 nam o hang(row) so: ");
        poVar2 = (ostream *)std::ostream::operator<<(poVar2,local_24);
        std::operator<<(poVar2,"\n");
      }
    }
  }
  for (local_3c = 0; local_3c < 5; local_3c = local_3c + 1) {
    for (local_40 = 0; local_40 < 5; local_40 = local_40 + 1) {
      if (*(int *)(local_d8 + ((longlong)local_3c * 5 + (longlong)local_40) * 4) == 0) {
        local_20 = local_20 + 1;
      }
      else {
        local_28 = local_20 % 5 + 1;
        poVar2 = std::operator<<((ostream *)&_ZSt4cout,"So 1 nam o cot(columns) so: ");
        poVar2 = (ostream *)std::ostream::operator<<(poVar2,local_28);
        std::operator<<(poVar2,"\n");
      }
    }
  }
  poVar2 = std::operator<<((ostream *)&_ZSt4cout,"So buoc can thuc hien: ");
  iVar3 = -(3 - local_28);
  if (iVar3 < 0) {
    iVar3 = 3 - local_28;
  }
  iVar4 = -(3 - local_24);
  iVar1 = 3 - local_24;
  if (-1 < iVar4) {
    iVar1 = iVar4;
  }
  std::ostream::operator<<(poVar2,iVar1 + iVar3);
  std::__cxx11::string::~string(local_68);
  return 0;
}



// operator delete(void*, unsigned long long)

void operator_delete(void *param_1,ulonglong param_2)

{
                    // WARNING: Could not recover jumptable at 0x0001400017c8. Too many branches
                    // WARNING: Treating indirect jump as call
  operator_delete(param_1,param_2);
  return;
}



// std::ostream& std::TEMPNAMEPLACEHOLDERVALUE(std::ostream&, char const*)

ostream * std::operator<<(ostream *param_1,char *param_2)

{
  ostream *poVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001400017d0. Too many branches
                    // WARNING: Treating indirect jump as call
  poVar1 = std::operator<<(param_1,param_2);
  return poVar1;
}



// std::ostream::TEMPNAMEPLACEHOLDERVALUE(int)

void __thiscall std::ostream::operator<<(ostream *this,int param_1)

{
                    // WARNING: Could not recover jumptable at 0x0001400017d8. Too many branches
                    // WARNING: Treating indirect jump as call
  std::ostream::operator<<(this,param_1);
  return;
}



// std::istream::TEMPNAMEPLACEHOLDERVALUE(int&)

void __thiscall std::istream::operator>>(istream *this,int *param_1)

{
                    // WARNING: Could not recover jumptable at 0x0001400017e0. Too many branches
                    // WARNING: Treating indirect jump as call
  std::istream::operator>>(this,param_1);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void __do_global_dtors(void)

{
  func_ptr p_Var1;
  
  p_Var1 = *__do_global_dtors::p;
  while (p_Var1 != (func_ptr)0x0) {
    (*p_Var1)();
    p_Var1 = __do_global_dtors::p[1];
    __do_global_dtors::p = __do_global_dtors::p + 1;
  }
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void __do_global_ctors(void)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  
  uVar2 = 0;
  do {
    uVar3 = uVar2;
    iVar1 = (int)uVar3;
    uVar2 = (ulonglong)(iVar1 + 1);
  } while (*(longlong *)(&__DELAY_IMPORT_DIRECTORY_end__ + (ulonglong)(iVar1 + 1) * 2) != 0);
  if (iVar1 != 0) {
    puVar4 = (undefined8 *)(&__DELAY_IMPORT_DIRECTORY_end__ + uVar3 * 2);
    do {
      (*(code *)*puVar4)();
      puVar4 = puVar4 + -1;
    } while (puVar4 != (undefined8 *)
                       ((longlong)pseudoRelocItemV2_ARRAY_140004a1c +
                       (uVar3 - (iVar1 - 1)) * 8 + 0x14));
  }
  atexit(__do_global_dtors);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void __main(void)

{
  if (initialized != 0) {
    return;
  }
  initialized = 1;
  __do_global_ctors();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int _setargv(void)

{
  return 0;
}



int _matherr(_exception *pexcept)

{
  double dVar1;
  double dVar2;
  double dVar3;
  char *pcVar4;
  FILE *_File;
  char *pcVar5;
  
                    // Unresolved local var: char * type@[???]
  switch(pexcept->type) {
  default:
    pcVar5 = "Unknown error";
    break;
  case 1:
    pcVar5 = "Argument domain error (DOMAIN)";
    break;
  case 2:
    pcVar5 = "Argument singularity (SIGN)";
    break;
  case 3:
    pcVar5 = "Overflow range error (OVERFLOW)";
    break;
  case 4:
    pcVar5 = "The result is too small to be represented (UNDERFLOW)";
    break;
  case 5:
    pcVar5 = "Total loss of significance (TLOSS)";
    break;
  case 6:
    pcVar5 = "Partial loss of significance (PLOSS)";
  }
  dVar1 = pexcept->retval;
  dVar2 = pexcept->arg2;
  dVar3 = pexcept->arg1;
  pcVar4 = pexcept->name;
  _File = __acrt_iob_func(2);
  fprintf((FILE *)_File,"_matherr(): %s in %s(%g, %g)  (retval=%g)\n",pcVar5,pcVar4,dVar3,dVar2,
          dVar1);
  return 0;
}



void __report_error(char *msg,...)

{
  FILE *pFVar1;
  undefined8 in_RDX;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  va_list argp;
  
  local_res10 = in_RDX;
  local_res18 = in_R8;
  local_res20 = in_R9;
  pFVar1 = __acrt_iob_func(2);
  fprintf((FILE *)pFVar1,"Mingw-w64 runtime failure:\n");
  pFVar1 = __acrt_iob_func(2);
  vfprintf((FILE *)pFVar1,msg,(va_list)&local_res10);
                    // WARNING: Subroutine does not return
  abort();
}



void mark_section_writable(LPVOID addr)

{
  uint uVar1;
  BOOL BVar2;
  DWORD DVar3;
  PBYTE *ppBVar4;
  PIMAGE_SECTION_HEADER p_Var5;
  sSecInfo *psVar6;
  PBYTE pBVar7;
  SIZE_T SVar8;
  ulonglong uVar9;
  int iVar10;
  MEMORY_BASIC_INFORMATION b;
  
                    // Unresolved local var: PIMAGE_SECTION_HEADER h@[???]
                    // Unresolved local var: int i@[???]
  uVar9 = (ulonglong)(uint)maxSections;
  if (maxSections < 1) {
    uVar9 = 0;
  }
  else {
    iVar10 = 0;
    ppBVar4 = &the_secs->sec_start;
    do {
      if ((*ppBVar4 <= addr) &&
         (addr < *ppBVar4 + (((PIMAGE_SECTION_HEADER)ppBVar4[1])->Misc).PhysicalAddress)) {
        return;
      }
      iVar10 = iVar10 + 1;
      ppBVar4 = ppBVar4 + 5;
    } while (iVar10 != maxSections);
  }
  p_Var5 = __mingw_GetSectionForAddress(addr);
  if (p_Var5 == (PIMAGE_SECTION_HEADER)0x0) {
                    // WARNING: Subroutine does not return
    __report_error("Address %p has no image-section",addr);
  }
  psVar6 = the_secs + uVar9;
  psVar6->hash = p_Var5;
  psVar6->old_protect = 0;
  pBVar7 = _GetPEImageBase();
  uVar1 = p_Var5->VirtualAddress;
  the_secs[uVar9].sec_start = pBVar7 + uVar1;
  SVar8 = VirtualQuery(pBVar7 + uVar1,(PMEMORY_BASIC_INFORMATION)&b,0x30);
  if (SVar8 != 0) {
    if (((b.Protect - 4 & 0xfffffffb) != 0) && ((b.Protect - 0x40 & 0xffffffbf) != 0)) {
                    // Unresolved local var: ULONG new_protect@[???]
      DVar3 = 0x40;
      if (b.Protect == 2) {
        DVar3 = 4;
      }
      psVar6 = the_secs + uVar9;
      psVar6->base_address = b.BaseAddress;
      psVar6->region_size = b.RegionSize;
      BVar2 = VirtualProtect(b.BaseAddress,b.RegionSize,DVar3,&psVar6->old_protect);
      if (BVar2 == 0) {
        DVar3 = GetLastError();
                    // WARNING: Subroutine does not return
        __report_error("  VirtualProtect failed with code 0x%x",(ulonglong)DVar3);
      }
    }
    maxSections = maxSections + 1;
    return;
  }
                    // WARNING: Subroutine does not return
  __report_error("  VirtualQuery failed for %d bytes at address %p",
                 (ulonglong)(p_Var5->Misc).PhysicalAddress,the_secs[uVar9].sec_start);
}



// WARNING: Function: ___chkstk_ms replaced with injection: alloca_probe
// WARNING: Removing unreachable block (ram,0x000140001c53)
// WARNING: Removing unreachable block (ram,0x000140001c5d)
// WARNING: Removing unreachable block (ram,0x000140001dd5)
// WARNING: Removing unreachable block (ram,0x000140001dde)
// WARNING: Removing unreachable block (ram,0x000140001df0)
// WARNING: Removing unreachable block (ram,0x000140001e20)
// WARNING: Removing unreachable block (ram,0x000140001c84)
// WARNING: Removing unreachable block (ram,0x000140001f53)
// WARNING: Unknown calling convention -- yet parameter storage is locked

void _pei386_runtime_relocator(void)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  DWORD flNewProtect;
  uint uVar4;
  SIZE_T dwSize;
  LPVOID lpAddress;
  longlong lVar5;
  int iVar6;
  longlong lVar7;
  DWORD *pDVar8;
  char *pcVar9;
  pseudoRelocItemV2 *ppVar10;
  longlong lVar11;
  char *addr;
  undefined8 auStack_80 [5];
  ptrdiff_t apStack_58 [3];
  ptrdiff_t reldata;
  
                    // Unresolved local var: int mSecs@[???]
  if (_pei386_runtime_relocator::was_init == 0) {
    _pei386_runtime_relocator::was_init = 1;
    auStack_80[0] = 0x140001bff;
    iVar6 = __mingw_GetSectionCount();
    auStack_80[0] = 0x140001c16;
                    // Unresolved local var: ptrdiff_t addr_imp@[???]
                    // Unresolved local var: ptrdiff_t reloc_target@[???]
                    // Unresolved local var: runtime_pseudo_reloc_v2 * v2_hdr@[???]
                    // Unresolved local var: runtime_pseudo_reloc_item_v2 * r@[???]
                    // Unresolved local var: uint bits@[???]
    lVar5 = -((longlong)iVar6 * 0x28 + 0xfU & 0xfffffffffffffff0);
    maxSections = 0;
    the_secs = (sSecInfo *)((longlong)apStack_58 + lVar5 + 0x10);
    ppVar10 = pseudoRelocItemV2_ARRAY_140004a1c;
    do {
      while( true ) {
        bVar1 = (byte)ppVar10->flags;
        pcVar9 = IMAGE_DOS_HEADER_140000000.e_magic + (uint)ppVar10->sym;
        addr = IMAGE_DOS_HEADER_140000000.e_magic + ppVar10->target;
        lVar11 = *(longlong *)pcVar9;
        if (bVar1 != 0x20) break;
        uVar4 = *(uint *)addr;
        if ((int)uVar4 < 0) {
          lVar7 = ((ulonglong)uVar4 | 0xffffffff00000000) - (longlong)pcVar9;
        }
        else {
          lVar7 = (ulonglong)uVar4 - (longlong)pcVar9;
        }
        reldata = lVar7 + lVar11;
        if ((0xffffffff < reldata) || (reldata < -0x80000000)) goto LAB_140001ef6;
        *(undefined8 *)((longlong)auStack_80 + lVar5) = 0x140001ec0;
        mark_section_writable(addr);
        *(undefined8 *)((longlong)auStack_80 + lVar5) = 0x140001ed1;
        memcpy(addr,&reldata,4);
LAB_140001cf4:
        ppVar10 = ppVar10 + 1;
        if ((pseudoRelocItemV2 *)((longlong)&pseudoRelocItemV2_ARRAY_140004a1c[1].flags + 3) <
            ppVar10) goto LAB_140001d60;
      }
      if (bVar1 < 0x21) {
        if (bVar1 == 8) {
          bVar2 = *addr;
          if ((char)bVar2 < '\0') {
            lVar7 = ((ulonglong)bVar2 | 0xffffffffffffff00) - (longlong)pcVar9;
          }
          else {
            lVar7 = (ulonglong)bVar2 - (longlong)pcVar9;
          }
          reldata = lVar7 + lVar11;
          if ((reldata < -0x80) || (0xff < reldata)) {
LAB_140001ef6:
            *(ptrdiff_t *)((longlong)apStack_58 + lVar5) = reldata;
                    // WARNING: Subroutine does not return
            *(undefined **)((longlong)auStack_80 + lVar5) = &UNK_140001f0a;
            __report_error("%d bit pseudo relocation at %p out of range, targeting %p, yielding the value %p.\n"
                           ,(ulonglong)bVar1,addr);
          }
          *(undefined8 *)((longlong)auStack_80 + lVar5) = 0x140001e66;
          mark_section_writable(addr);
          *(undefined8 *)((longlong)auStack_80 + lVar5) = 0x140001e77;
          memcpy(addr,&reldata,1);
        }
        else {
          if (bVar1 != 0x10) goto LAB_140001f3f;
          uVar3 = *(ushort *)addr;
          if ((short)uVar3 < 0) {
            lVar7 = ((ulonglong)uVar3 | 0xffffffffffff0000) - (longlong)pcVar9;
                    // Unresolved local var: ptrdiff_t max_unsigned@[???]
                    // Unresolved local var: ptrdiff_t min_signed@[???]
          }
          else {
            lVar7 = (ulonglong)uVar3 - (longlong)pcVar9;
          }
          reldata = lVar7 + lVar11;
          if ((reldata < -0x8000) || (0xffff < reldata)) goto LAB_140001ef6;
          *(undefined8 *)((longlong)auStack_80 + lVar5) = 0x140001ce3;
          mark_section_writable(addr);
          *(undefined8 *)((longlong)auStack_80 + lVar5) = 0x140001cf4;
          memcpy(addr,&reldata,2);
        }
        goto LAB_140001cf4;
      }
      if (bVar1 != 0x40) {
LAB_140001f3f:
        reldata = 0;
                    // WARNING: Subroutine does not return
        *(undefined8 *)((longlong)auStack_80 + lVar5) = 0x140001f53;
        __report_error("  Unknown pseudo relocation bit size %d.\n");
      }
      ppVar10 = ppVar10 + 1;
      reldata = (*(longlong *)addr - (longlong)pcVar9) + lVar11;
      *(undefined8 *)((longlong)auStack_80 + lVar5) = 0x140001d45;
      mark_section_writable(addr);
      *(undefined8 *)((longlong)auStack_80 + lVar5) = 0x140001d56;
      memcpy(addr,&reldata,8);
    } while (ppVar10 < (pseudoRelocItemV2 *)&__RUNTIME_PSEUDO_RELOC_LIST_END__);
LAB_140001d60:
                    // Unresolved local var: int i@[???]
    if (0 < maxSections) {
      lVar11 = 0;
      iVar6 = 0;
      do {
        pDVar8 = (DWORD *)((longlong)&the_secs->old_protect + lVar11);
        flNewProtect = *pDVar8;
        if (flNewProtect != 0) {
          dwSize = *(SIZE_T *)(pDVar8 + 4);
          lpAddress = *(LPVOID *)(pDVar8 + 2);
          *(undefined8 *)((longlong)auStack_80 + lVar5) = 0x140001d9f;
          VirtualProtect(lpAddress,dwSize,flNewProtect,(PDWORD)&reldata);
        }
        iVar6 = iVar6 + 1;
        lVar11 = lVar11 + 0x28;
      } while (iVar6 < maxSections);
      return;
    }
  }
  return;
}



void __mingw_raise_matherr(int typ,char *name,double a1,double a2,double rslt)

{
  _exception ex;
  
  if (stUserMathErr != (fUserMathErr)0x0) {
    ex.retval = rslt;
    ex.type = typ;
    ex.name = name;
    ex.arg1 = a1;
    ex.arg2 = a2;
    (*stUserMathErr)(&ex);
  }
  return;
}



void __mingw_setusermatherr(_func_int__exception_ptr *f)

{
  stUserMathErr = f;
  __setusermatherr();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void _fpreset(void)

{
  return;
}



WINBOOL _ValidateImageBase(PBYTE pImageBase)

{
                    // Unresolved local var: PIMAGE_DOS_HEADER pDOSHeader@[DW_OP_reg2(RCX)]
                    // Unresolved local var: PIMAGE_NT_HEADERS pNTHeader@[???]
                    // Unresolved local var: PIMAGE_OPTIONAL_HEADER pOptHeader@[???]
                    // Unresolved local var: PIMAGE_DOS_HEADER pDOSHeader@[???]
                    // Unresolved local var: PIMAGE_NT_HEADERS pNTHeader@[???]
                    // Unresolved local var: PIMAGE_OPTIONAL_HEADER pOptHeader@[???]
  if ((*(short *)pImageBase == 0x5a4d) &&
     (*(int *)(pImageBase + *(int *)(pImageBase + 0x3c)) == 0x4550)) {
    return (WINBOOL)((short)*(int *)((longlong)(pImageBase + *(int *)(pImageBase + 0x3c)) + 0x18) ==
                    0x20b);
  }
  return 0;
}



PIMAGE_SECTION_HEADER _FindPESection(PBYTE pImageBase,DWORD_PTR rva)

{
  PIMAGE_SECTION_HEADER p_Var1;
  int iVar2;
  PIMAGE_SECTION_HEADER p_Var3;
  
                    // Unresolved local var: PIMAGE_NT_HEADERS pNTHeader@[???]
                    // Unresolved local var: PIMAGE_SECTION_HEADER pSection@[???]
                    // Unresolved local var: uint iSection@[???]
  iVar2 = *(int *)(pImageBase + 0x3c);
  if (*(ushort *)(pImageBase + (longlong)iVar2 + 6) != 0) {
    p_Var3 = (PIMAGE_SECTION_HEADER)
             (pImageBase +
             (ulonglong)*(ushort *)(pImageBase + (longlong)iVar2 + 0x14) + (longlong)iVar2 + 0x18);
    p_Var1 = p_Var3 + (ulonglong)(*(ushort *)(pImageBase + (longlong)iVar2 + 6) - 1) + 1;
    do {
      if ((p_Var3->VirtualAddress <= rva) &&
         (rva < p_Var3->VirtualAddress + (p_Var3->Misc).PhysicalAddress)) {
        return p_Var3;
      }
      p_Var3 = p_Var3 + 1;
    } while (p_Var3 != p_Var1);
  }
  return (PIMAGE_SECTION_HEADER)0x0;
}



// WARNING: Removing unreachable block (ram,0x00014000205d)
// WARNING: Enum "SectionFlags": Some values do not have unique names

PIMAGE_SECTION_HEADER __mingw_GetSectionForAddress(LPVOID p)

{
  IMAGE_SECTION_HEADER *pIVar1;
  
                    // Unresolved local var: PIMAGE_NT_HEADERS pNTHeader@[???]
                    // Unresolved local var: PIMAGE_SECTION_HEADER pSection@[???]
                    // Unresolved local var: uint iSection@[???]
  pIVar1 = &IMAGE_SECTION_HEADER_140000188;
  while (((longlong)p - 0x140000000U < (ulonglong)((PIMAGE_SECTION_HEADER)pIVar1)->VirtualAddress ||
         ((ulonglong)
          (((PIMAGE_SECTION_HEADER)pIVar1)->VirtualAddress +
          ((Misc *)&((PIMAGE_SECTION_HEADER)pIVar1)->Misc)->PhysicalAddress) <=
          (longlong)p - 0x140000000U))) {
    pIVar1 = pIVar1 + 1;
    if ((PIMAGE_SECTION_HEADER)pIVar1 == (PIMAGE_SECTION_HEADER)&DAT_140000458) {
      return (PIMAGE_SECTION_HEADER)0x0;
    }
  }
  return (PIMAGE_SECTION_HEADER)pIVar1;
}



// WARNING: Removing unreachable block (ram,0x0001400020dd)
// WARNING: Unknown calling convention -- yet parameter storage is locked

int __mingw_GetSectionCount(void)

{
                    // Unresolved local var: PBYTE pImageBase@[???]
                    // Unresolved local var: PIMAGE_NT_HEADERS pNTHeader@[???]
                    // Unresolved local var: PIMAGE_DOS_HEADER pDOSHeader@[???]
                    // Unresolved local var: PIMAGE_OPTIONAL_HEADER pOptHeader@[???]
                    // Unresolved local var: PIMAGE_DOS_HEADER pDOSHeader@[???]
                    // Unresolved local var: PIMAGE_NT_HEADERS pNTHeader@[???]
                    // Unresolved local var: PIMAGE_OPTIONAL_HEADER pOptHeader@[???]
  return 0x12;
}



// WARNING: Removing unreachable block (ram,0x00014000211b)
// WARNING: Removing unreachable block (ram,0x00014000210d)
// WARNING: Unknown calling convention -- yet parameter storage is locked

PBYTE _GetPEImageBase(void)

{
                    // Unresolved local var: PBYTE pImageBase@[???]
                    // Unresolved local var: PIMAGE_DOS_HEADER pDOSHeader@[???]
                    // Unresolved local var: PIMAGE_NT_HEADERS pNTHeader@[???]
                    // Unresolved local var: PIMAGE_OPTIONAL_HEADER pOptHeader@[???]
                    // Unresolved local var: PIMAGE_DOS_HEADER pDOSHeader@[???]
                    // Unresolved local var: PIMAGE_NT_HEADERS pNTHeader@[???]
                    // Unresolved local var: PIMAGE_OPTIONAL_HEADER pOptHeader@[???]
  return (PBYTE)&IMAGE_DOS_HEADER_140000000;
}



// WARNING: This is an inlined function

ulonglong ___chkstk_ms(void)

{
  ulonglong in_RAX;
  ulonglong uVar1;
  undefined8 *puVar2;
  undefined8 local_res8 [4];
  
  puVar2 = local_res8;
  uVar1 = in_RAX;
  if (0xfff < in_RAX) {
    do {
      puVar2 = puVar2 + -0x200;
      *puVar2 = *puVar2;
      uVar1 = uVar1 - 0x1000;
    } while (0x1000 < uVar1);
  }
  *(undefined8 *)((longlong)puVar2 - uVar1) = *(undefined8 *)((longlong)puVar2 - uVar1);
  return in_RAX;
}



int _initterm_e(_PIFV *first_func,_PIFV *last_func)

{
  int iVar1;
  
  while( true ) {
    if (last_func <= first_func) {
      return 0;
    }
    if ((*first_func != (_PIFV)0x0) && (iVar1 = (**first_func)(), iVar1 != 0)) break;
    first_func = first_func + 1;
  }
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int * __p__fmode(void)

{
  return (int *)_fmode_exref;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int * __p__commode(void)

{
  return (int *)_commode_exref;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char *** __p___initenv(void)

{
  return (char ***)__initenv_exref;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

_invalid_parameter_handler mingw_get_invalid_parameter_handler(void)

{
  return handler;
}



_invalid_parameter_handler
mingw_set_invalid_parameter_handler(_invalid_parameter_handler new_handler)

{
  _invalid_parameter_handler p_Var1;
  
  p_Var1 = handler;
  LOCK();
  handler = new_handler;
  UNLOCK();
  return p_Var1;
}



int _configthreadlocale(int flag)

{
  return -(uint)((flag & 0xfffffffdU) != 0) | 2;
}



FILE * __acrt_iob_func(uint index)

{
  FILE *pFVar1;
  
  pFVar1 = __iob_func();
  return (FILE *)(pFVar1 + index);
}



int __cdecl _XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x000140002230. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = _XcptFilter(_ExceptionNum,_ExceptionPtr);
  return iVar1;
}



void __getmainargs(void)

{
                    // WARNING: Could not recover jumptable at 0x000140002238. Too many branches
                    // WARNING: Treating indirect jump as call
  __getmainargs();
  return;
}



FILE * __cdecl __iob_func(void)

{
  FILE *pFVar1;
  
                    // WARNING: Could not recover jumptable at 0x000140002240. Too many branches
                    // WARNING: Treating indirect jump as call
  pFVar1 = __iob_func();
  return pFVar1;
}



void __cdecl __set_app_type(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x000140002248. Too many branches
                    // WARNING: Treating indirect jump as call
  __set_app_type(param_1);
  return;
}



void __setusermatherr(void)

{
                    // WARNING: Could not recover jumptable at 0x000140002250. Too many branches
                    // WARNING: Treating indirect jump as call
  __setusermatherr();
  return;
}



void __cdecl _amsg_exit(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x000140002258. Too many branches
                    // WARNING: Treating indirect jump as call
  _amsg_exit(param_1);
  return;
}



void __cdecl _cexit(void)

{
                    // WARNING: Could not recover jumptable at 0x000140002260. Too many branches
                    // WARNING: Treating indirect jump as call
  _cexit();
  return;
}



void __cdecl _exit(int _Code)

{
                    // WARNING: Could not recover jumptable at 0x000140002268. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  _exit(_Code);
  return;
}



void _initterm(void)

{
                    // WARNING: Could not recover jumptable at 0x000140002270. Too many branches
                    // WARNING: Treating indirect jump as call
  _initterm();
  return;
}



void __cdecl abort(void)

{
                    // WARNING: Could not recover jumptable at 0x000140002278. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  abort();
  return;
}



int __cdecl _crt_atexit(_func_5014 *param_1)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x000140002280. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = atexit(param_1);
  return iVar1;
}



void __cdecl exit(int _Code)

{
                    // WARNING: Could not recover jumptable at 0x000140002288. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  exit(_Code);
  return;
}



int __cdecl fflush(FILE *_File)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x000140002290. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = fflush(_File);
  return iVar1;
}



int __cdecl fprintf(FILE *_File,char *_Format,...)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x000140002298. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = fprintf(_File,_Format);
  return iVar1;
}



FILE * __cdecl freopen(char *_Filename,char *_Mode,FILE *_File)

{
  FILE *pFVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001400022a0. Too many branches
                    // WARNING: Treating indirect jump as call
  pFVar1 = freopen(_Filename,_Mode,_File);
  return pFVar1;
}



void * __cdecl malloc(size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001400022a8. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = malloc(_Size);
  return pvVar1;
}



void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001400022b0. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



int __cdecl setvbuf(FILE *_File,char *_Buf,int _Mode,size_t _Size)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001400022b8. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = setvbuf(_File,_Buf,_Mode,_Size);
  return iVar1;
}



size_t __cdecl strlen(char *_Str)

{
  size_t sVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001400022c0. Too many branches
                    // WARNING: Treating indirect jump as call
  sVar1 = strlen(_Str);
  return sVar1;
}



int __cdecl vfprintf(FILE *_File,char *_Format,va_list _ArgList)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001400022c8. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = vfprintf(_File,_Format,_ArgList);
  return iVar1;
}



SIZE_T __stdcall VirtualQuery(LPCVOID lpAddress,PMEMORY_BASIC_INFORMATION lpBuffer,SIZE_T dwLength)

{
  SIZE_T SVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001400022d0. Too many branches
                    // WARNING: Treating indirect jump as call
  SVar1 = VirtualQuery(lpAddress,lpBuffer,dwLength);
  return SVar1;
}



BOOL __stdcall
VirtualProtect(LPVOID lpAddress,SIZE_T dwSize,DWORD flNewProtect,PDWORD lpflOldProtect)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001400022d8. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = VirtualProtect(lpAddress,dwSize,flNewProtect,lpflOldProtect);
  return BVar1;
}



void __stdcall Sleep(DWORD dwMilliseconds)

{
                    // WARNING: Could not recover jumptable at 0x0001400022e0. Too many branches
                    // WARNING: Treating indirect jump as call
  Sleep(dwMilliseconds);
  return;
}



LPTOP_LEVEL_EXCEPTION_FILTER __stdcall
SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter)

{
  LPTOP_LEVEL_EXCEPTION_FILTER pPVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001400022e8. Too many branches
                    // WARNING: Treating indirect jump as call
  pPVar1 = SetUnhandledExceptionFilter(lpTopLevelExceptionFilter);
  return pPVar1;
}



DWORD __stdcall GetLastError(void)

{
  DWORD DVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001400022f0. Too many branches
                    // WARNING: Treating indirect jump as call
  DVar1 = GetLastError();
  return DVar1;
}



// std::__cxx11::string::_M_is_local() const

bool __thiscall std::__cxx11::string::_M_is_local(string *this)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = _M_data(this);
  lVar2 = _M_local_data(this);
  return lVar1 == lVar2;
}



// std::__cxx11::string::_M_local_data() const

void __thiscall std::__cxx11::string::_M_local_data(string *this)

{
  __ptr_traits_ptr_to<char_const*,char_const,false>::pointer_to(this + 0x10);
  return;
}



// std::__cxx11::string::_M_data() const

undefined8 __thiscall std::__cxx11::string::_M_data(string *this)

{
  return *(undefined8 *)this;
}



// std::char_traits<char>::assign(char&, char const&)

void std::char_traits<char>::assign(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  return;
}



// std::__new_allocator<char>::deallocate(char*, unsigned long long)

void __thiscall
std::__new_allocator<char>::deallocate(undefined8 param_1_00,void *param_2,ulonglong param_3)

{
  operator_delete(param_2,param_3);
  return;
}



// std::__new_allocator<char>::~__new_allocator()

void __thiscall std::__new_allocator<char>::~__new_allocator(void)

{
  return;
}



// std::__ptr_traits_ptr_to<char const*, char const, false>::pointer_to(char const&)

undefined8 std::__ptr_traits_ptr_to<char_const*,char_const,false>::pointer_to(undefined8 param_1)

{
  return param_1;
}



// std::__ptr_traits_ptr_to<char*, char, false>::pointer_to(char&)

undefined8 std::__ptr_traits_ptr_to<char*,char,false>::pointer_to(undefined8 param_1)

{
  return param_1;
}



// std::__cxx11::string::_M_destroy(unsigned long long)

void __thiscall std::__cxx11::string::_M_destroy(string *this,longlong param_1)

{
  void *pvVar1;
  string *psVar2;
  
  pvVar1 = (void *)_M_data(this);
  psVar2 = _M_get_allocator(this);
  __new_allocator<char>::deallocate(psVar2,pvVar1,param_1 + 1);
  return;
}



// std::__cxx11::string::_M_dispose()

void __thiscall std::__cxx11::string::_M_dispose(string *this)

{
  bool bVar1;
  
  bVar1 = _M_is_local(this);
  if (!bVar1) {
    _M_destroy(this,*(longlong *)(this + 0x10));
  }
  return;
}



// std::__cxx11::string::_Alloc_hider::_Alloc_hider(char*, std::allocator<char>&&)

void __thiscall
std::__cxx11::string::_Alloc_hider::_Alloc_hider(_Alloc_hider *this,undefined8 param_1)

{
  *(undefined8 *)this = param_1;
  return;
}



// std::__cxx11::string::_Alloc_hider::~_Alloc_hider()

void __thiscall std::__cxx11::string::_Alloc_hider::~_Alloc_hider(void)

{
  __new_allocator<char>::~__new_allocator();
  return;
}



// std::__cxx11::string::_M_local_data()

void __thiscall std::__cxx11::string::_M_local_data(string *this)

{
  __ptr_traits_ptr_to<char*,char,false>::pointer_to(this + 0x10);
  return;
}



// std::__cxx11::string::_M_set_length(unsigned long long)

void __thiscall std::__cxx11::string::_M_set_length(string *this,longlong param_1)

{
  longlong lVar1;
  undefined1 local_9;
  
  local_9 = 0;
  lVar1 = _M_data(this);
  char_traits<char>::assign((undefined1 *)(lVar1 + param_1),&local_9);
  _M_length(this,param_1);
  return;
}



// std::__cxx11::string::_M_get_allocator()

string * __thiscall std::__cxx11::string::_M_get_allocator(string *this)

{
  return this;
}



// std::__cxx11::string::_M_length(unsigned long long)

void __thiscall std::__cxx11::string::_M_length(string *this,undefined8 param_1)

{
  *(undefined8 *)(this + 8) = param_1;
  return;
}



// std::__cxx11::string::string()

void __thiscall std::__cxx11::string::string(string *this)

{
  undefined8 uVar1;
  undefined1 local_29;
  undefined1 *local_28;
  string *local_20;
  
  local_28 = &local_29;
  uVar1 = _M_local_data(this);
  _Alloc_hider::_Alloc_hider((_Alloc_hider *)this,uVar1);
  __new_allocator<char>::~__new_allocator();
  local_20 = this;
  _M_set_length(this,0);
  return;
}



// std::__cxx11::string::~string()

void __thiscall std::__cxx11::string::~string(string *this)

{
  _M_dispose(this);
  _Alloc_hider::~_Alloc_hider();
  return;
}



void register_frame_ctor(void)

{
  atexit(__gcc_deregister_frame);
  return;
}



