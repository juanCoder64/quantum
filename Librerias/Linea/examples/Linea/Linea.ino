/*
                                                `/ohhhhs+.
                                              -hMMMMMMMMMMd/
                                            .hMMmo:.``.-+hMMm/
                                           /NMd:          `+NMy`
                                          sMm:              .yMd`
                        `/sdNNMMNNdhs+:. sMy`                 +Mm``-+sydmNNMNNdy+.
                      `sNMMMmyo+///osydNNMm:`                 -hMNNdhso+///osdMMMMd-
                     `mMMNs.           -My+ymds:          .+hmho+Ms           `/mMMN:
                     oMMm.            `md    `/sdy/`   :sdh+-    +M:             yMMm
                     dMM:             oN.        .+dhyms:         hm              mMM.
                     dMN             `N+         .ods+hy:         .M+             sMM.
                     oMN`            sm        /hy-    .odo`       sm             sMm
              `      .MM-           `N+     `+h+`         :ys-     .M:            mMo
             +Nssssssssssssssssssssssssssssss:              .osssssssssssssssssssssssssssyM-
             +m                                                                          .M-
             +m                                                                          .M-
             +m                                                                          .M-
             ./                                   /+++++-                                `s`
                          /+++/.  o`   /:   /:    m.   `m.  -++++: `sssss+ :+++/`
                         m:   `.  N+///h+  osy/   msooood- os    +h   d-  `m+/:-
                         d/   ./  N-...y+ omoom/  m-````os +s`  `oy   d-  `-``.yo
                          :+++:`  +`   :-.+    +` +ooooo/`  `/++/.    /.  `:+++/`
                                      ..`
                                    o- `oo`. .  `  ` `  :````. ``` `
              .                     m.  `d.d d`/-h d.o/.m./s`m y:++-h                     --
             .M.                    -y/++.`o-o.o.o`o.:+`s..o.s`+-:+.o`                    hy
             .M.                    `  `-`                                                hy
             .M.                                                                          hy
             .M:.............................                `............................hy
             `+++++++oMMyooooooooooooMyooooosh/            -yh+++++oMy+++++++++++oNMy++++++:
                     /MM`            dy       /hs.      `+ho`      /M.            hMh
                     hMm             :M-        -sh+` :yy/         my             oMM`
                     dMM.             dd          `yMNm-          +M.             dMM.
                     hMMs             -M+      .+ydo.`/hdo-      .Ns             -MMM`
                     -MMMy.            sM: ./ymh+.      `/ymh+-``mm`            +NMMy
                      /NMMMy/-`     `.:oMMNdo:`             -+hNNMh/-.`    `.:smMMMy`
                       `omMMMMMNNNNMMNhs+mN:                  `dMsoymMMNNNNMMMMMNy-
                          `-//++//-.`    .mM+                -mM/     .-//+++/:.
                                          .dMd-            `sMM:
                                            sMMh/`       -yNMd.
                                             .yMMMdhyshdNMMm/
                                               .odMMMMMMmy:
                                                   .-:-`
*/
#include <Linea.h>
Linea frente(A0, A1, A2, 50);
Linea izq(A3, A4, A5, 51);
Linea der(A6, A7, A8, 52);
Linea abajo(A9, A10, A11, 53);
void setup() {
  Serial.begin(9600);
  Serial.println("poner todos los sensores en verde");
  for (int i = 0; i < 5; i++) {
    Serial.println(i+1);
    delay(1000);
  }  frente.calibrarV();
  izq.calibrarV();
  der.calibrarV();
  abajo.calibrarV();
  Serial.println("poner los sensores laterales en blanco");
  for (int i = 0; i < 5; i++) {
    Serial.println(i+1);
    delay(1000);
  }
  izq.calibrarV();
  der.calibrarV();
  Serial.println("poner los sensores de arriba y abajo en blanco");
  for (int i = 0; i < 5; i++) {
    Serial.println(i+1);
    delay(1000);
  }
  frente.calibrarB();
  abajo.calibrarV();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(izq.lectura());
  Serial.print("\t");
  Serial.print(frente.lectura());
  Serial.print("\t");
  Serial.print(abajo.lectura());
  Serial.print("\t");
  Serial.println(der.lectura());
}
