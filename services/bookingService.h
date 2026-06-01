#ifndef BOOKING_SERVICE_H
#define BOOKING_SERVICE_H

// BookingService.h
// Здесь объявляется сервис бронирования.
//
// BookingService — главный класс бизнес-логики.
//
// Что должен уметь BookingService:
// 1. bookSeat(User& user, Event& event, Seat& seat, FareStrategy& fare)
// 2. Проверять доступность места.
// 3. Рассчитывать финальную стоимость билета.
// 4. Проверять баланс пользователя.
// 5. Списывать деньги.
// 6. Менять состояние места.
// 7. Создавать Ticket.
// 8. Возвращать созданный Ticket.
//
// Важно:
// Именно BookingService отвечает за транзакцию.
// То есть все шаги должны пройти успешно.
// Если хотя бы один шаг не прошел — билет не создается.

#endif // BOOKING_SERVICE_H