// 600432e8  FUN_600432e8  size=750 bytes
// --- callers ---
// --- callees ---
//   6004703c FUN_6004703c
//   60047968 FUN_60047968
//   60042300 FUN_60042300
//   60048248 FUN_60048248


void FUN_600432e8(int param_1)

{
  undefined *puVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  bool bVar12;
  char cStack_d9;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined2 uStack_c8;
  undefined1 uStack_c6;
  undefined *puStack_c4;
  undefined *puStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined2 uStack_b4;
  undefined1 uStack_b2;
  
  cVar2 = func_0x6004c224();
  if (cVar2 != '\0') {
    func_0x6004c304(0x28,PTR_s_input_task_cc_600435dc,0xdd,
                    PTR_s_Failed_to_load_calibration_from_K_600435d8);
  }
  puVar1 = PTR_LAB_600d407e_1_600435e0;
  puStack_c4 = PTR_LAB_600d407e_1_600435e0;
  puStack_c0 = PTR_LAB_6007637c_1_600435e4;
  func_0x6004c37c(PTR_LAB_600d407e_1_600435e0,PTR_LAB_6007637c_1_600435e4);
  puStack_c4 = PTR_LAB_600dac30_1_600435e8;
  puStack_c0 = PTR_LAB_600dac36_1_600435ec;
  func_0x6004c13c(PTR_LAB_600dac30_1_600435e8,PTR_LAB_600dac36_1_600435ec);
  puStack_c4 = puVar1;
  puStack_c0 = PTR_FUN_600dac8a_1_600435f0;
  func_0x6004c194(puVar1,PTR_FUN_600dac8a_1_600435f0);
  uVar7 = *(undefined4 *)(param_1 + 0x3a4);
  uVar3 = FUN_60047968();
  FUN_60048248(uVar7,1,uVar3,0,10);
  puStack_c4 = (undefined *)((uint)puStack_c4 & 0xffffff00);
  iVar4 = func_0x6004beac();
  if (((iVar4 == 0) ||
      (cVar2 = func_0x6004c40c(0x2e,&puStack_c4), puVar1 = PTR_s_input_task_cc_600435dc,
      cVar2 != '\0')) || ((char)puStack_c4 == '\0')) {
    *(undefined1 *)(param_1 + 0x415) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x415) = 1;
    func_0x6004c304(0x14,puVar1,0xe6,PTR_s_Enabling_debug_button_press_LED_60043604);
  }
  bVar11 = false;
  uVar9 = 0;
  iVar10 = 0;
  iVar4 = 0;
  cStack_d9 = '\0';
  do {
    uVar5 = FUN_6004703c(*(undefined4 *)(param_1 + 0x78),0xf,1,0,0xffffffff);
    if ((uVar5 & 8) != 0) {
      func_0x6004c0cc(param_1,&cStack_d9);
    }
    puVar1 = PTR_s_input_601218db_0x19_600435f4;
    if ((uVar5 & 1) != 0) {
      cStack_d9 = '\x01';
    }
    if ((uVar5 & 2) != 0) {
      bVar12 = 0xfffffffe < uVar9;
      uVar9 = uVar9 + 1;
      iVar10 = iVar10 + (uint)bVar12;
      FUN_60042300(0xc,uVar9,4,0,PTR_s_input_601218db_0x19_600435f4,0,PTR_s_sample_600435f8);
      FUN_60042300(0xc,uVar9,4,0,puVar1,0,PTR_s_input_task_600435fc);
      uVar6 = FUN_60047968();
      iVar8 = ((uVar6 % 1000) * 1000 + 500) / 1000 + (uVar6 / 1000) * 1000;
      uStack_d8 = *(undefined4 *)(param_1 + 0x210);
      uStack_d4 = *(undefined4 *)(param_1 + 0x214);
      uStack_d0 = *(undefined4 *)(param_1 + 0x218);
      uStack_cc = *(undefined4 *)(param_1 + 0x21c);
      uVar3 = *(undefined4 *)(param_1 + 0x220);
      uStack_c8 = (undefined2)uVar3;
      uStack_c6 = (undefined1)((uint)uVar3 >> 0x10);
      iVar4 = func_0x60043028(param_1,iVar8,uVar9,iVar10);
      puStack_c4 = *(undefined **)(param_1 + 0x210);
      puStack_c0 = *(undefined **)(param_1 + 0x214);
      uStack_bc = *(undefined4 *)(param_1 + 0x218);
      uStack_b8 = *(undefined4 *)(param_1 + 0x21c);
      uVar3 = *(undefined4 *)(param_1 + 0x220);
      uStack_b4 = (undefined2)uVar3;
      uStack_b2 = (undefined1)((uint)uVar3 >> 0x10);
      func_0x60049522(param_1,iVar8,&uStack_d8,&puStack_c4);
      puVar1 = PTR_s_input_601218db_0x19_600435f4;
      if (iVar4 == 0) {
        FUN_60042300(0xe,uVar9,4,0,PTR_s_input_601218db_0x19_600435f4,0,PTR_s_input_task_600435fc);
        FUN_60042300(0xe,uVar9,4,0,puVar1,0,PTR_s_sample_600435f8);
      }
      else if ((((((*(int *)(param_1 + 0x234) == 0) && (*(int *)(param_1 + 0x238) == 0)) &&
                 ((*(int *)(param_1 + 0x224) == 0x800 &&
                  ((*(int *)(param_1 + 0x228) == 0x800 && (*(int *)(param_1 + 0x22c) == 0x800))))))
                && (((*(int *)(param_1 + 0x230) == 0x800 &&
                     ((((*(char *)(param_1 + 0x210) == '\0' && (*(char *)(param_1 + 0x211) == '\0'))
                       && (*(char *)(param_1 + 0x212) == '\0')) &&
                      ((*(char *)(param_1 + 0x213) == '\0' && (*(char *)(param_1 + 0x214) == '\0')))
                      ))) && (((*(char *)(param_1 + 0x215) == '\0' &&
                               ((*(char *)(param_1 + 0x216) == '\0' &&
                                (*(char *)(param_1 + 0x217) == '\0')))) &&
                              (*(char *)(param_1 + 0x218) == '\0')))))) &&
               ((((*(char *)(param_1 + 0x219) == '\0' && (*(char *)(param_1 + 0x21a) == '\0')) &&
                 (*(char *)(param_1 + 0x21b) == '\0')) &&
                ((*(char *)(param_1 + 0x21c) == '\0' && (*(char *)(param_1 + 0x21d) == '\0')))))) &&
              ((((*(char *)(param_1 + 0x21e) == '\0' &&
                 ((*(char *)(param_1 + 0x21f) == '\0' && (*(char *)(param_1 + 0x220) == '\0')))) &&
                (*(char *)(param_1 + 0x221) == '\0')) && (*(char *)(param_1 + 0x222) == '\0')))) {
        if (bVar11) {
          cVar2 = func_0x6004c46c(*(undefined4 *)(param_1 + 0x418));
          bVar11 = cVar2 != '\0';
        }
      }
      else if (!bVar11) {
        cVar2 = func_0x6004c0e4(*(undefined4 *)(param_1 + 0x418));
        bVar11 = cVar2 == '\0';
      }
    }
    if (((uVar5 & 4) != 0) && (uVar5 = func_0x6004c224(), (uVar5 & 0xff) != 0)) {
      func_0x6004c2fc(&puStack_c4,PTR_s_input_task_cc_600435dc,0x10c,uVar5);
      func_0x6004c444(&uStack_bc,PTR_s_Failed_to_load_calibration_from_K_60043600);
      func_0x6004c254(&puStack_c4);
    }
    if ((cStack_d9 != '\0') && (iVar4 != 0)) {
      iVar4 = 0;
      cStack_d9 = '\0';
      func_0x6004323c(param_1);
    }
  } while( true );
}


